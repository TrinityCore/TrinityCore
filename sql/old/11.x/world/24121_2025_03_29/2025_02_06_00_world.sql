SET @CGUID := 10005865;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+86;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2026.6441650390625, -3243.072998046875, 152.9502716064453125, 3.550134181976318359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+1, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 1988.717041015625, -3148.802001953125, 153.757568359375, 3.189591646194458007, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+2, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2116.052001953125, -3203.80908203125, 148.6272430419921875, 2.689475297927856445, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2097.87841796875, -3246.083251953125, 157.4198455810546875, 3.032810688018798828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+4, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2040.2117919921875, -3207.08154296875, 150.182647705078125, 5.366449832916259765, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 222619, 2552, 14717, 0, '0', 0, 0, 0, 0, 2082.56591796875, -3215.677001953125, 150.136260986328125, 5.344310760498046875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+6, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2071.291748046875, -3191.842041015625, 147.811920166015625, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 222619, 2552, 14717, 0, '0', 0, 0, 0, 0, 1998.7257080078125, -3164.22216796875, 152.7284088134765625, 5.303539276123046875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+8, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2009.3836669921875, -3178.350830078125, 152.532867431640625, 6.261461257934570312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+9, 222618, 2552, 14717, 0, '0', 0, 0, 0, 0, 2036.4739990234375, -3199.138916015625, 150.5236968994140625, 2.721597194671630859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Alert Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+10, 222619, 2552, 14717, 0, '0', 0, 0, 0, 0, 2042.736083984375, -3240.369873046875, 151.9337158203125, 5.308138370513916015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+11, 222223, 2552, 14717, 0, '0', 0, 0, 0, 0, 2002.501708984375, -3178.725830078125, 180.8037109375, 1.114737987518310546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Watchful Falcon (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 222618, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2087.53125, -3289.354248046875, 155.098175048828125, 0.80707097053527832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Alert Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+13, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2137.48095703125, -3332.1962890625, 154.3462677001953125, 1.458431839942932128, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+14, 222223, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2184.616455078125, -3281.248291015625, 164.039947509765625, 5.966811180114746093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Watchful Falcon (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+15, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2150.975830078125, -3314.84033203125, 151.100494384765625, 1.029682040214538574, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+16, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2124.232666015625, -3338.84033203125, 155.971221923828125, 4.577866554260253906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+17, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2103.984375, -3279.2431640625, 152.3334808349609375, 3.875568389892578125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+18, 222223, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2100.333251953125, -3227.7744140625, 182.1505126953125, 0.539541482925415039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Watchful Falcon (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+19, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2141.467041015625, -3262.76220703125, 144.079254150390625, 4.068400382995605468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+20, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2095.83154296875, -3302.005126953125, 154.624176025390625, 4.236026763916015625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+21, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2193.6962890625, -3290.34033203125, 141.4801025390625, 2.67884230613708496, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+22, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2187.388916015625, -3279.875, 140.828765869140625, 0.847741603851318359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+23, 222618, 2552, 14717, 0, '0', 0, 0, 0, 0, 2186.8369140625, -3327.3125, 152.041656494140625, 5.37554788589477539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Alert Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+24, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2182.12841796875, -3354.217041015625, 155.470458984375, 1.571449875831604003, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+25, 222619, 2552, 14717, 0, '0', 0, 0, 0, 0, 2189.20654296875, -3339.03125, 153.475494384765625, 4.108139514923095703, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 219171, 2552, 14717, 0, '0', 0, 0, 0, 0, 2220.791748046875, -3322.382080078125, 144.577972412109375, 5.055685043334960937, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2255.670166015625, -3373.713623046875, 154.314849853515625, 3.413090705871582031, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+28, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2284.1181640625, -3314.57470703125, 144.5194091796875, 5.37844085693359375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2379.0400390625, -3316.625, 158.56707763671875, 1.836205840110778808, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+30, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2259.1650390625, -3344.40625, 152.0195159912109375, 5.5726470947265625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2350.291748046875, -3316.041748046875, 154.6397552490234375, 5.780545711517333984, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+32, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2280.689208984375, -3358.47216796875, 154.4567108154296875, 0.033099275082349777, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+33, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2303.005126953125, -3340.572998046875, 153.1151885986328125, 0.705207288265228271, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+34, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2360.97216796875, -3323.604248046875, 154.869781494140625, 3.316060066223144531, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+35, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2343.842041015625, -3341.505126953125, 153.3029327392578125, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+36, 222618, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2353.970458984375, -3339.65966796875, 153.4531707763671875, 6.036624431610107421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Alert Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+37, 222223, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2311.819580078125, -3340.02783203125, 186.38714599609375, 1.829318165779113769, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Watchful Falcon (Area: The Proscenium - Difficulty: 0) CreateObject2
(@CGUID+38, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2011.001708984375, -3356.479248046875, 124.1712570190429687, 3.796596050262451171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+39, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1996.2239990234375, -3357.640625, 122.569732666015625, 2.109104633331298828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+40, 221520, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1998.6041259765625, -3391.392333984375, 113.553924560546875, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Puddle Skipper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+41, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1943.1771240234375, -3390.916748046875, 115.0059738159179687, 0.726257264614105224, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+42, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1959.7864990234375, -3335.760498046875, 124.9739990234375, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+43, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1964.810791015625, -3381.5556640625, 114.6131362915039062, 4.980790615081787109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+44, 221520, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2022.703125, -3388.03125, 111.9137191772460937, 5.655106544494628906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Puddle Skipper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+45, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2026.90283203125, -3368.15625, 123.207733154296875, 2.529989480972290039, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+46, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1830.5364990234375, -3292.579833984375, 145.264434814453125, 1.374449968338012695, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+47, 222199, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1825.3367919921875, -3290.99658203125, 129.956512451171875, 2.287687540054321289, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Spring Waddler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+48, 221520, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1860.545166015625, -3392.01904296875, 118.4715423583984375, 0.113999448716640472, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Puddle Skipper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+49, 220298, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2629.8515625, -3419.09033203125, 176.5399322509765625, 5.016522407531738281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+50, 220298, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2639.79345703125, -3442.53125, 178.264923095703125, 4.670010566711425781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+51, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2638.450439453125, -3430.6650390625, 184.044403076171875, 6.232574939727783203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+52, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2632.015625, -3409.59716796875, 175.109161376953125, 1.361237764358520507, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+53, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2568.9931640625, -3447.69091796875, 172.1968536376953125, 1.08595430850982666, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+54, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2570.481689453125, -3453.276123046875, 173.5747833251953125, 2.841748714447021484, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+55, 216017, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2574.3359375, -3419.98095703125, 168.9325408935546875, 6.244348526000976562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Great Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+56, 216017, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2623.065185546875, -3479.420166015625, 172.967010498046875, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Great Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+57, 220298, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2663.138916015625, -3521.791748046875, 187.258453369140625, 0.585603535175323486, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+58, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2654.251708984375, -3523.814208984375, 185.3840789794921875, 5.511596202850341796, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+59, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2703.126708984375, -3457.5400390625, 187.960723876953125, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+60, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2683.66064453125, -3421.6494140625, 186.2073211669921875, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+61, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2669.72998046875, -3496.65283203125, 184.2958526611328125, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+62, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2670.795166015625, -3526.857666015625, 188.819793701171875, 0.302856266498565673, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 78677 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+63, 220295, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2627.0322265625, -3543.923583984375, 209.231781005859375, 4.954974651336669921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallside Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+64, 222780, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2698.095458984375, -3445.111083984375, 187.26953125, 3.665754318237304687, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Fragrant Stonelamb (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+65, 220297, 2552, 14717, 14787, '0', 0, 0, 0, 0, 2584.5244140625, -3546.373291015625, 179.975799560546875, 6.059347152709960937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Mourning Rise - Difficulty: 0) CreateObject2
(@CGUID+66, 220298, 2552, 14717, 14787, '0', 0, 0, 0, 0, 2616.41845703125, -3688.96533203125, 225.465576171875, 3.65711832046508789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: Mourning Rise - Difficulty: 0) CreateObject2
(@CGUID+67, 218401, 2552, 14717, 14787, '0', 0, 0, 0, 0, 2586.45751953125, -3563.689208984375, 181.856475830078125, 5.683023929595947265, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Mourning Rise - Difficulty: 0) CreateObject2
(@CGUID+68, 220295, 2552, 14717, 14787, '0', 0, 0, 0, 0, 2682.201416015625, -3549.72216796875, 204.4139556884765625, 3.821574926376342773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallside Falcon (Area: Mourning Rise - Difficulty: 0) CreateObject2
(@CGUID+69, 220297, 2552, 14717, 14787, '0', 0, 0, 0, 0, 2637.8916015625, -3583.286376953125, 195.568634033203125, 0.309972882270812988, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Mourning Rise - Difficulty: 0) CreateObject2
(@CGUID+70, 222780, 2552, 14717, 0, '0', 0, 0, 0, 0, 2700.50341796875, -3200.55908203125, 199.393341064453125, 5.237896919250488281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Fragrant Stonelamb (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+71, 220297, 2552, 14717, 0, '0', 0, 0, 0, 0, 2756.470458984375, -3353.796875, 192.3130950927734375, 2.03247690200805664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+72, 220298, 2552, 14717, 0, '0', 0, 0, 0, 0, 2792.34716796875, -3277.598876953125, 206.336029052734375, 3.32674574851989746, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+73, 216017, 2552, 14717, 0, '0', 0, 0, 0, 0, 2795.19970703125, -3331.296875, 204.43975830078125, 3.529891014099121093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Great Stormfang (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+74, 218401, 2552, 14717, 0, '0', 0, 0, 0, 0, 2795.19970703125, -3331.296875, 204.43975830078125, 2.753201961517333984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+75, 218401, 2552, 14717, 0, '0', 0, 0, 0, 0, 2759.661376953125, -3341.05029296875, 194.33782958984375, 0.45895126461982727, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+76, 220295, 2552, 14717, 0, '0', 0, 0, 0, 0, 2720.7587890625, -3337.00341796875, 192.3961029052734375, 3.262367725372314453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallside Falcon (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+77, 220298, 2552, 14717, 0, '0', 0, 0, 0, 0, 2714.43310546875, -3256.10595703125, 192.3877716064453125, 2.305187702178955078, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+78, 220298, 2552, 14717, 0, '0', 0, 0, 0, 0, 2782.116455078125, -3299.635498046875, 203.370880126953125, 4.834767341613769531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Mouse (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+79, 218401, 2552, 14717, 0, '0', 0, 0, 0, 0, 2758.8759765625, -3224.076416015625, 205.92962646484375, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+80, 220295, 2552, 14717, 0, '0', 0, 0, 0, 0, 2720.427001953125, -3223.677001953125, 207.913726806640625, 5.317508220672607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallside Falcon (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+81, 220297, 2552, 14717, 0, '0', 0, 0, 0, 0, 2791.825439453125, -3237.56591796875, 210.41815185546875, 0.117298923432826995, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+82, 222747, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2850.30029296875, -3117.920166015625, 231.2357025146484375, 4.548746109008789062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Mossy Snail (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+83, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2850.91845703125, -3149.65283203125, 227.9934539794921875, 4.688039302825927734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+84, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2873.52783203125, -3188.89404296875, 266.386383056640625, 1.522764801979064941, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+85, 214973, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2852.092041015625, -3209.59375, 220.564239501953125, 1.038187026977539062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Shalehorn Bull (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+86, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2848.017333984375, -3209.30908203125, 220.7752685546875, 0.928108513355255126, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911); -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+86;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Scavenging Stormfang - 78677 - Cosmetic - Sleep Zzz Breakable
(@CGUID+68, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fallside Falcon
(@CGUID+76, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Fallside Falcon

-- Template
UPDATE `creature_template` SET `faction`=31, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=220298; -- Forest Mouse
UPDATE `creature_template` SET `faction`=2952, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=218401; -- Scavenging Stormfang
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=220295; -- Fallside Falcon
UPDATE `creature_template` SET `faction`=31, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=220297; -- Tiny Marmot
UPDATE `creature_template` SET `faction`=1953, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=216017; -- Great Stormfang
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=214764; -- Rustmane Shalehorn
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=214973; -- Shalehorn Bull

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=220298 AND `DifficultyID`=0); -- 220298 (Forest Mouse) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=218401 AND `DifficultyID`=0); -- 218401 (Scavenging Stormfang) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000000, `VerifiedBuild`=58911 WHERE (`Entry`=220295 AND `DifficultyID`=0); -- 220295 (Fallside Falcon) - CanSwim - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=220297 AND `DifficultyID`=0); -- 220297 (Tiny Marmot) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=216017 AND `DifficultyID`=0); -- 216017 (Great Stormfang) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=214764 AND `DifficultyID`=0); -- 214764 (Rustmane Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=214973 AND `DifficultyID`=0); -- 214973 (Shalehorn Bull) - CanSwim

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (@CGUID+68, @CGUID+76);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+68, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+76, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 222223;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1778, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2199.164, -3286.0107, 164.03995, NULL, 0),
(@PATH, 1, 2206.0833, -3299.665, 164.03995, NULL, 0),
(@PATH, 2, 2201.3208, -3314.2126, 164.03995, NULL, 0),
(@PATH, 3, 2187.6667, -3321.1318, 164.03995, NULL, 0),
(@PATH, 4, 2173.119, -3316.3694, 164.03995, NULL, 0),
(@PATH, 5, 2166.1997, -3302.715, 164.03995, NULL, 0),
(@PATH, 6, 2170.9622, -3288.1675, 164.03995, NULL, 0),
(@PATH, 7, 2184.6165, -3281.2483, 164.03995, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 222223;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1777, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2113.466, -3219.9104, 182.15051, NULL, 0),
(@PATH, 1, 2128.3132, -3223.6362, 182.15051, NULL, 0),
(@PATH, 2, 2136.177, -3236.769, 182.15051, NULL, 0),
(@PATH, 3, 2132.4514, -3251.616, 182.15051, NULL, 0),
(@PATH, 4, 2119.3186, -3259.48, 182.15051, NULL, 0),
(@PATH, 5, 2104.4714, -3255.7544, 182.15051, NULL, 0),
(@PATH, 6, 2096.6074, -3242.6213, 182.15051, NULL, 0),
(@PATH, 7, 2100.3333, -3227.7744, 182.15051, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 222223;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1777, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2009.2433, -3164.983, 180.80371, NULL, 0),
(@PATH, 1, 2023.7279, -3160.0322, 180.80371, NULL, 0),
(@PATH, 2, 2037.4707, -3166.7737, 180.80371, NULL, 0),
(@PATH, 3, 2042.4215, -3181.2585, 180.80371, NULL, 0),
(@PATH, 4, 2035.6799, -3195.0012, 180.80371, NULL, 0),
(@PATH, 5, 2021.1953, -3199.952, 180.80371, NULL, 0),
(@PATH, 6, 2007.4524, -3193.2104, 180.80371, NULL, 0),
(@PATH, 7, 2002.5017, -3178.7258, 180.80371, NULL, 0),
(@PATH, 8, 2009.2433, -3164.983, 180.80371, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+37;
SET @ENTRY := 222223;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1777, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2307.9062, -3325.2292, 186.38715, NULL, 0),
(@PATH, 1, 2315.6035, -3311.9978, 186.38715, NULL, 0),
(@PATH, 2, 2330.4023, -3308.0847, 186.38715, NULL, 0),
(@PATH, 3, 2343.6335, -3315.7817, 186.38715, NULL, 0),
(@PATH, 4, 2347.5469, -3330.5806, 186.38715, NULL, 0),
(@PATH, 5, 2339.8496, -3343.8118, 186.38715, NULL, 0),
(@PATH, 6, 2325.0508, -3347.725, 186.38715, NULL, 0),
(@PATH, 7, 2311.8196, -3340.0278, 186.38715, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Alert Shalehorn
SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 222618;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Alert Shalehorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2416.4463, -3329.9219, 151.86395, NULL, 0),
(@PATH, 1, 2444.691, -3321.356, 151.68971, NULL, 0),
(@PATH, 2, 2461.658, -3324.533, 150.38467, NULL, 6757),
(@PATH, 3, 2444.691, -3321.356, 151.68971, NULL, 0),
(@PATH, 4, 2416.4463, -3329.9219, 151.86395, NULL, 0),
(@PATH, 5, 2381.4548, -3337.5608, 154.01526, NULL, 0),
(@PATH, 6, 2359.0696, -3338.394, 153.61838, NULL, 7359),
(@PATH, 7, 2381.4548, -3337.5608, 154.01526, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Soaring Plainshawk
SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 221644;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Soaring Plainshawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1832.8201, -3281.0994, 145.26443, NULL, 0),
(@PATH, 1, 1839.3232, -3271.3667, 145.26443, NULL, 0),
(@PATH, 2, 1849.056, -3264.8635, 145.26443, NULL, 0),
(@PATH, 3, 1860.5365, -3262.5798, 145.26443, NULL, 0),
(@PATH, 4, 1872.017, -3264.8635, 145.26443, NULL, 0),
(@PATH, 5, 1881.7498, -3271.3667, 145.26443, NULL, 0),
(@PATH, 6, 1888.2529, -3281.0994, 145.26443, NULL, 0),
(@PATH, 7, 1890.5365, -3292.5798, 145.26443, NULL, 0),
(@PATH, 8, 1888.2529, -3304.0603, 145.26443, NULL, 0),
(@PATH, 9, 1881.7498, -3313.793, 145.26443, NULL, 0),
(@PATH, 10, 1872.017, -3320.2961, 145.26443, NULL, 0),
(@PATH, 11, 1860.5365, -3322.5798, 145.26443, NULL, 0),
(@PATH, 12, 1849.056, -3320.2961, 145.26443, NULL, 0),
(@PATH, 13, 1839.3232, -3313.793, 145.26443, NULL, 0),
(@PATH, 14, 1832.8201, -3304.0603, 145.26443, NULL, 0),
(@PATH, 15, 1830.5365, -3292.5798, 145.26443, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Scavenging Stormfang
SET @MOVERGUID := @CGUID+61;
SET @ENTRY := 218401;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Scavenging Stormfang - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2651.4766, -3453.6997, 179.32382, NULL, 0),
(@PATH, 1, 2651.9644, -3438.0676, 180.66322, NULL, 0),
(@PATH, 2, 2658.8118, -3429.8542, 181.91548, NULL, 0),
(@PATH, 3, 2667.9375, -3439.665, 183.05716, NULL, 0),
(@PATH, 4, 2673.7551, -3451.2883, 184.6552, NULL, 0),
(@PATH, 5, 2673.5034, -3466.9895, 184.15315, NULL, 0),
(@PATH, 6, 2682.8047, -3471.9895, 186.29514, NULL, 0),
(@PATH, 7, 2693.2612, -3482.2864, 188.54495, NULL, 0),
(@PATH, 8, 2701.962, -3493.9202, 188.5279, NULL, 0),
(@PATH, 9, 2705.519, -3505.566, 190.10901, NULL, 0),
(@PATH, 10, 2672.1064, -3508.517, 185.44424, NULL, 0);

UPDATE `creature` SET `position_x`=2651.4766, `position_y`=-3453.6997, `position_z`=179.32382, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Great Stormfang
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+73;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+73, @CGUID+73, 0, 0, 515, 0, 0),
(@CGUID+73, @CGUID+74, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 216017;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Great Stormfang - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2762.097, -3313.5732, 197.71292, NULL, 0),
(@PATH, 1, 2760.6309, -3310.9517, 197.09206, NULL, 0),
(@PATH, 2, 2759.1802, -3308.358, 196.41228, NULL, 0),
(@PATH, 3, 2757.722, -3305.7505, 195.94608, NULL, 0),
(@PATH, 4, 2756.2688, -3303.1526, 195.60223, NULL, 0),
(@PATH, 5, 2754.7654, -3300.4758, 195.33803, NULL, 0),
(@PATH, 6, 2753.816, -3295.6785, 195.85712, NULL, 0),
(@PATH, 7, 2753.884, -3292.6523, 196.43794, NULL, 0),
(@PATH, 8, 2753.952, -3289.6233, 196.99553, NULL, 0),
(@PATH, 9, 2754.0198, -3286.6016, 197.4357, NULL, 0),
(@PATH, 10, 2754.089, -3283.512, 197.64557, NULL, 0),
(@PATH, 11, 2754.151, -3280.4905, 197.60313, NULL, 0),
(@PATH, 12, 2756.247, -3275.8904, 197.93822, NULL, 0),
(@PATH, 13, 2757.9292, -3273.3716, 198.3518, NULL, 0),
(@PATH, 14, 2759.6133, -3270.85, 198.78741, NULL, 0),
(@PATH, 15, 2761.2876, -3268.3428, 199.24811, NULL, 0),
(@PATH, 16, 2762.9387, -3265.8706, 199.74954, NULL, 0),
(@PATH, 17, 2764.6226, -3263.3494, 200.28519, NULL, 0),
(@PATH, 18, 2766.2722, -3260.8792, 200.81757, NULL, 0),
(@PATH, 19, 2767.9207, -3258.4106, 201.34978, NULL, 0),
(@PATH, 20, 2774.1467, -3254.954, 203.02237, NULL, 0),
(@PATH, 21, 2777.0452, -3255.7776, 203.3952, NULL, 0),
(@PATH, 22, 2779.938, -3256.5999, 203.82326, NULL, 0),
(@PATH, 23, 2782.8267, -3257.421, 204.30724, NULL, 0),
(@PATH, 24, 2785.7043, -3258.239, 204.94933, NULL, 0),
(@PATH, 25, 2788.5764, -3259.0554, 205.59967, NULL, 0),
(@PATH, 26, 2791.3477, -3259.8398, 206.20451, NULL, 0),
(@PATH, 27, 2795.7498, -3263.106, 206.88129, NULL, 0),
(@PATH, 28, 2797.5212, -3265.6118, 207.07507, NULL, 0),
(@PATH, 29, 2799.25, -3268.0574, 207.40482, NULL, 0),
(@PATH, 30, 2800.95, -3270.462, 207.93161, NULL, 0),
(@PATH, 31, 2802.6416, -3272.855, 208.64066, NULL, 0),
(@PATH, 32, 2804.3484, -3275.269, 209.36362, NULL, 0),
(@PATH, 33, 2806.0803, -3277.719, 210.00978, NULL, 0),
(@PATH, 34, 2807.8086, -3280.1638, 210.50923, NULL, 0),
(@PATH, 35, 2809.5596, -3282.6406, 210.88463, NULL, 0),
(@PATH, 36, 2811.5864, -3285.732, 211.15479, NULL, 0),
(@PATH, 37, 2812.8154, -3288.5044, 211.17154, NULL, 0),
(@PATH, 38, 2814.0627, -3291.318, 211.09552, NULL, 0),
(@PATH, 39, 2815.2898, -3294.086, 211.02588, NULL, 0),
(@PATH, 40, 2816.5364, -3296.8958, 210.9231, NULL, 0),
(@PATH, 41, 2817.7673, -3299.6702, 210.75215, NULL, 0),
(@PATH, 42, 2819.074, -3304.0754, 210.36398, NULL, 0),
(@PATH, 43, 2819.0332, -3307.076, 209.9393, NULL, 0),
(@PATH, 44, 2818.992, -3310.0955, 209.48013, NULL, 0),
(@PATH, 45, 2818.95, -3313.1514, 209.01617, NULL, 0),
(@PATH, 46, 2818.9092, -3316.1326, 208.58168, NULL, 0),
(@PATH, 47, 2816.8123, -3321.3828, 207.43152, NULL, 0),
(@PATH, 48, 2814.7021, -3323.5134, 206.68286, NULL, 0),
(@PATH, 49, 2812.6177, -3325.618, 206.17404, NULL, 0),
(@PATH, 50, 2810.4673, -3327.7893, 205.91664, NULL, 0),
(@PATH, 51, 2808.3545, -3329.922, 205.98624, NULL, 0),
(@PATH, 52, 2804.8242, -3332.6553, 205.88477, NULL, 0),
(@PATH, 53, 2802.0295, -3333.8484, 205.40509, NULL, 0),
(@PATH, 54, 2799.3027, -3335.0122, 204.71948, NULL, 0),
(@PATH, 55, 2796.5813, -3336.1736, 203.91028, NULL, 0),
(@PATH, 56, 2793.855, -3337.337, 203.04625, NULL, 0),
(@PATH, 57, 2791.2383, -3338.457, 202.27435, NULL, 0),
(@PATH, 58, 2784.6157, -3337.9824, 200.65237, NULL, 0),
(@PATH, 59, 2782.291, -3336.041, 200.04645, NULL, 0),
(@PATH, 60, 2779.9102, -3334.0503, 199.67374, NULL, 0),
(@PATH, 61, 2777.5425, -3332.0715, 199.22949, NULL, 0),
(@PATH, 62, 2775.1956, -3330.1104, 198.98131, NULL, 0),
(@PATH, 63, 2772.9158, -3328.205, 198.68039, NULL, 0),
(@PATH, 64, 2770.5725, -3326.247, 198.30865, NULL, 0),
(@PATH, 65, 2767.5154, -3323.2617, 197.84589, NULL, 0),
(@PATH, 66, 2766.0408, -3320.6245, 197.83432, NULL, 0),
(@PATH, 67, 2764.5735, -3318.0012, 197.9125, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Fallside Falcon
SET @MOVERGUID := @CGUID+63;
SET @ENTRY := 220295;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.6630, 'Fallside Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2631.1033, -3560.375, 212.97034, NULL, 0),
(@PATH, 1, 2630.519, -3590.1824, 212.90263, NULL, 0),
(@PATH, 2, 2663.6494, -3612.2551, 212.97034, NULL, 0),
(@PATH, 3, 2715.7249, -3607.7986, 212.97034, NULL, 0),
(@PATH, 4, 2761.1086, -3566.8716, 212.97034, NULL, 0),
(@PATH, 5, 2755.0442, -3501.2952, 212.97034, NULL, 0),
(@PATH, 6, 2700.4922, -3482.9827, 212.97034, NULL, 0),
(@PATH, 7, 2644.4375, -3490.2708, 212.97034, NULL, 0),
(@PATH, 8, 2634.0574, -3534.3213, 212.97034, NULL, 0),
(@PATH, 9, 2631.1033, -3560.375, 212.97034, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Fallside Falcon
SET @MOVERGUID := @CGUID+80;
SET @ENTRY := 220295;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.0222, 'Fallside Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2724.5747, -3229.6736, 209.6948, NULL, 0),
(@PATH, 1, 2734.9602, -3246.144, 209.6948, NULL, 0),
(@PATH, 2, 2737.6997, -3265.7432, 209.6948, NULL, 0),
(@PATH, 3, 2723.8699, -3282.0833, 209.6948, NULL, 0),
(@PATH, 4, 2687.0112, -3290.5017, 209.6948, NULL, 0),
(@PATH, 5, 2655.8838, -3260.0676, 209.6948, NULL, 0),
(@PATH, 6, 2675.6267, -3230.1511, 209.6948, NULL, 0),
(@PATH, 7, 2704.427, -3220.4028, 209.6948, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+84;
SET @ENTRY := 214772;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5455, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2874.0898, -3177.2021, 269.38638, NULL, 0),
(@PATH, 1, 2870.1348, -3166.185, 269.38638, NULL, 0),
(@PATH, 2, 2862.2646, -3157.5203, 269.38638, NULL, 0),
(@PATH, 3, 2851.6777, -3152.5269, 269.38638, NULL, 0),
(@PATH, 4, 2839.9858, -3151.9648, 269.38638, NULL, 0),
(@PATH, 5, 2828.969, -3155.92, 269.38638, NULL, 0),
(@PATH, 6, 2820.3042, -3163.7898, 269.38638, NULL, 0),
(@PATH, 7, 2815.3105, -3174.3767, 269.38638, NULL, 0),
(@PATH, 8, 2814.7485, -3186.0686, 269.38638, NULL, 0),
(@PATH, 9, 2818.7036, -3197.0857, 269.38638, NULL, 0),
(@PATH, 10, 2826.5737, -3205.7505, 269.38638, NULL, 0),
(@PATH, 11, 2837.1606, -3210.7441, 269.38638, NULL, 0),
(@PATH, 12, 2848.8525, -3211.306, 269.38638, NULL, 0),
(@PATH, 13, 2859.8694, -3207.3508, 269.38638, NULL, 0),
(@PATH, 14, 2868.5344, -3199.481, 269.38638, NULL, 0),
(@PATH, 15, 2873.5278, -3188.894, 269.38638, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Shalehorn Bull
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+85;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+85, @CGUID+85, 0, 0, 515, 0, 0),
(@CGUID+85, @CGUID+86, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+85;
SET @ENTRY := 214973;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shalehorn Bull - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2859.1824, -3132.4878, 227.56061, NULL, 0),
(@PATH, 1, 2845.9514, -3126.736, 229.18213, NULL, 0),
(@PATH, 2, 2830.3967, -3129.7917, 231.62204, NULL, 0),
(@PATH, 3, 2808.5105, -3145.6077, 234.80281, NULL, 0),
(@PATH, 4, 2796.1458, -3154.2205, 235.19324, NULL, 0),
(@PATH, 5, 2793.1042, -3170.6494, 230.08603, NULL, 0),
(@PATH, 6, 2793.9836, -3186.8176, 227.605, NULL, 0),
(@PATH, 7, 2799.9714, -3196.934, 227.86502, NULL, 0),
(@PATH, 8, 2811.1614, -3201.8525, 226.20273, NULL, 0),
(@PATH, 9, 2818.5322, -3203.8682, 224.41429, NULL, 0),
(@PATH, 10, 2826.2449, -3214.2378, 221.40317, NULL, 0),
(@PATH, 11, 2833.691, -3217.1406, 221.04027, NULL, 0),
(@PATH, 12, 2841.8716, -3214.691, 220.64275, NULL, 0),
(@PATH, 13, 2857.3628, -3204.007, 221.10628, NULL, 0),
(@PATH, 14, 2860.994, -3194.4844, 222.13354, NULL, 0),
(@PATH, 15, 2864.0808, -3182.9167, 222.58641, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
