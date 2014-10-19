SET @CGUID := 361957;
SET @OGUID := 226287;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+85;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0,  23511, 0, 1, 1, 0, -9118.646, 325.2996, 93.31362, 1.919862, 120, 0, 0), -- Gordok Brew Apprentice (Area: Elwynn Forest)
(@CGUID+1,  23510, 0, 1, 1, 0, -9114.785, 338.7653, 93.62766, 2.9147, 120, 0, 0), -- Thunderbrew Apprentice (Area: Elwynn Forest)
(@CGUID+2,  23482, 0, 1, 1, 0, -9118.479, 348.4555, 93.94923, 3.787364, 120, 0, 0), -- Barleybrew Apprentice (Area: Elwynn Forest)
(@CGUID+3,  24484, 0, 1, 1, 0, -9130.688, 333.9394, 93.3105, 0.8372726, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+4,  24484, 0, 1, 1, 0, -9130.905, 344.5025, 93.73042, 0.9424778, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 44337 - Brewfest Reveler - Dwarf - Male)
(@CGUID+5,  24484, 0, 1, 1, 0, -9129.28, 362.6293, 92.37377, 4.11774, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+6,  24484, 0, 1, 1, 0, -9131.846, 358.8361, 92.3964, 0.9761472, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+7,  24484, 0, 1, 1, 0, -9130.678, 347.4707, 93.63763, 5.67232, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+8,  24484, 0, 1, 1, 0, -9127.974, 347.9314, 93.93057, 3.874631, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 44338 - Brewfest Reveler - Dwarf - Female)
(@CGUID+9,  24484, 0, 1, 1, 0, -9128.346, 345.3679, 94.05936, 2.687807, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 44337 - Brewfest Reveler - Dwarf - Male)
(@CGUID+10, 24484, 0, 1, 1, 0, -9126.819, 338.2312, 93.92828, 3.040008, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+11, 24484, 0, 1, 1, 0, -9142.217, 339.8008, 91.34106, 3.194332, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+12, 24484, 0, 1, 1, 0, -9145.262, 339.64, 90.67572, 0.0527393, 120, 0, 0), -- Brewfest Reveler (Area: Elwynn Forest) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+13, 24364, 0, 1, 1, 0, -5609.832, -459.0559, 404.6329, 5.305801, 120, 0, 0), -- Flynn Firebrew (Area: Dun Morogh) (Auras: 44067 - Supplier Mark)
(@CGUID+14, 24468, 0, 1, 1, 0, -5200.865, -484.7043, 388.8812, 3.420845, 120, 0, 0), -- Pol Amberstill (Area: Dun Morogh) (Auras: 44068 - Base Camp Mark)
(@CGUID+15, 23558, 0, 1, 1, 0, -5200.164, -491.5487, 388.5592, 3.193953, 120, 0, 0), -- Neill Ramstein (Area: Dun Morogh)
(@CGUID+16, 23521, 0, 1, 1, 0, -5172.943, -628.0436, 397.2595, 1.186824, 120, 0, 0), -- Anne Summers (Area: Dun Morogh)
(@CGUID+17, 23710, 0, 1, 1, 0, -5176.905, -624.3687, 397.947, 0.715585, 120, 0, 0), -- Belbi Quikswitch (Area: Dun Morogh)
(@CGUID+18, 23482, 0, 1, 1, 0, -5185.083, -608.2559, 397.2595, 0.5061455, 120, 0, 0), -- Barleybrew Apprentice (Area: Dun Morogh)
(@CGUID+19, 23627, 0, 1, 1, 0, -5184.127, -611.7972, 397.2595, 0.4886922, 120, 0, 0), -- Becan Barleybrew (Area: Dun Morogh)
(@CGUID+20, 23808, 0, 1, 1, 0, -5184.132, -601.8058, 397.3012, 0.9056421, 120, 5, 1), -- [DND] Brewfest Keg Move to Target (Area: Dun Morogh) (possible waypoints or random movement)
(@CGUID+21, 23683, 0, 1, 1, 0, -5181.018, -613.8245, 397.3012, 0.3839724, 120, 0, 0), -- Maeve Barleybrew (Area: Dun Morogh) (Auras: )
(@CGUID+22, 23488, 0, 1, 1, 0, -5175.604, -597.0005, 397.7565, 0.5585054, 120, 0, 0), -- Brewfest Crowd (Area: Dun Morogh)
(@CGUID+23, 23522, 0, 1, 1, 0, -5187.463, -586.1702, 397.3405, 0.1905907, 120, 0, 0), -- Arlen Lochlan (Area: Dun Morogh)
(@CGUID+24, 24766, 0, 1, 1, 0, -5165.246, -603.4328, 398.0052, 2.530727, 120, 0, 0), -- [DND] Brewfest Face Me Bunny (Area: Dun Morogh)
(@CGUID+25, 23808, 0, 1, 1, 0, -5158.501, -629.8905, 397.2245, 2.806662, 120, 5, 1), -- [DND] Brewfest Keg Move to Target (Area: Dun Morogh) (possible waypoints or random movement)
(@CGUID+26, 23628, 0, 1, 1, 0, -5146.556, -633.5544, 397.2642, 1.64061, 120, 0, 0), -- Daran Thunderbrew (Area: Dun Morogh)
(@CGUID+27, 23510, 0, 1, 1, 0, -5149.612, -634.2039, 397.2647, 1.727876, 120, 0, 0), -- Thunderbrew Apprentice (Area: Dun Morogh)
(@CGUID+28, 23703, 0, 1, 1, 0, -5152.337, -604.9965, 398.5365, 5.602507, 120, 0, 0), -- [DND] Brewfest Dark Iron Event Generator (Area: Dun Morogh)
(@CGUID+29, 23684, 0, 1, 1, 0, -5143.186, -630.371, 397.2245, 1.623156, 120, 0, 0), -- Ita Thunderbrew (Area: Dun Morogh) (Auras: )
(@CGUID+30, 23486, 0, 1, 1, 0, -5172.919, -562.5673, 397.2595, 3.455752, 120, 0, 0), -- Goldark Snipehunter (Area: Dun Morogh)
(@CGUID+31, 24710, 0, 1, 1, 0, -5184.684, -562.372, 397.2595, 2.111848, 120, 0, 0), -- Ipfelkofer Ironkeg (Area: Dun Morogh)
(@CGUID+32, 23525, 0, 1, 1, 0, -5164.674, -568.4444, 397.2595, 3.961897, 120, 0, 0), -- Brother Cartwright (Area: Dun Morogh)
(@CGUID+33, 24484, 0, 1, 1, 0, -5210.784, -506.0679, 388.5051, 5.524828, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43908 - Brewfest Reveler - Draenei)
(@CGUID+34, 24484, 0, 1, 1, 0, -5210.184, -512.9577, 389.5921, 0.8085682, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43913 - Brewfest Reveler - Night Elf)
(@CGUID+35, 24766, 0, 1, 1, 0, -5209.471, -488.2339, 388.9122, 3.036873, 120, 0, 0), -- [DND] Brewfest Face Me Bunny (Area: Dun Morogh)
(@CGUID+36, 24463, 0, 1, 1, 0, -5188.07, -488.7207, 386.8857, 6.055955, 120, 0, 0), -- Swift Racing Ram (Area: Dun Morogh)
(@CGUID+37, 24484, 0, 1, 1, 0, -5194.188, -519.2751, 390.2625, 1.958588, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+38, 24484, 0, 1, 1, 0, -5207.015, -509.6384, 388.825, 3.950161, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+39, 24484, 0, 1, 1, 0, -5195.685, -515.6113, 389.714, 5.100181, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+40, 27215, 0, 1, 1, 0, -5185.336, -540.1724, 397.2031, 3.351032, 120, 0, 0), -- Boxey Boltspinner (Area: Dun Morogh)
(@CGUID+41, 24462, 0, 1, 1, 0, -5185.82, -484.808, 387.0292, 3.42718, 120, 0, 0), -- Racing Ram (Area: Dun Morogh)
(@CGUID+42, 24108, 0, 1, 1, 0, -5167.972, -539.4572, 397.2624, 1.678377, 120, 5, 1), -- Self-Turning and Oscillating Utility Target (Area: Dun Morogh) (possible waypoints or random movement)
(@CGUID+43, 24109, 0, 1, 1, 0, -5168.079, -538.463, 397.2599, 5.288348, 120, 0, 0), -- [DND] Brewfest Target Dummy Move To Target (Area: Dun Morogh)
(@CGUID+44, 24109, 0, 1, 1, 0, -5167.119, -547.3276, 397.2595, 1.48353, 120, 0, 0), -- [DND] Brewfest Target Dummy Move To Target (Area: Dun Morogh)
(@CGUID+45, 23808, 0, 1, 1, 0, -5148.264, -577.6766, 397.3012, 2.556881, 120, 5, 1), -- [DND] Brewfest Keg Move to Target (Area: Dun Morogh) (possible waypoints or random movement)
(@CGUID+46, 23706, 0, 1, 1, 0, -5146.527, -576.4496, 397.2595, 3.804818, 120, 0, 0), -- Gordok Festive Keg (Area: Dun Morogh)
(@CGUID+47, 23511, 0, 1, 1, 0, -5139.066, -579.3162, 397.2595, 4.031711, 120, 0, 0), -- Gordok Brew Apprentice (Area: Dun Morogh)
(@CGUID+48, 24484, 0, 1, 1, 0, -5170.149, -578.8616, 397.3678, 2.303835, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43913 - Brewfest Reveler - Night Elf)
(@CGUID+49, 23698, 0, 1, 1, 0, -5190.509, -553.5136, 397.2794, 1.993462, 120, 0, 0), -- Drunken Brewfest Reveler (Area: Dun Morogh) (Auras: 43905 - Completely Hammered, 35777 - Bloodmaul Intoxication Visual)
(@CGUID+50, 24484, 0, 1, 1, 0, -5179.541, -596.7141, 397.4122, 4.976364, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43910 - Brewfest Reveler - Gnome)
(@CGUID+51, 24484, 0, 1, 1, 0, -5166.657, -586.2771, 397.8213, 3.188444, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43913 - Brewfest Reveler - Night Elf)
(@CGUID+52, 24484, 0, 1, 1, 0, -5172.547, -586.5533, 397.906, 4.349577, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+53, 24484, 0, 1, 1, 0, -5165.994, -608.4224, 397.6673, 0.2851539, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+54, 24484, 0, 1, 1, 0, -5161.28, -607.0406, 398.0949, 3.426747, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+55, 24484, 0, 1, 1, 0, -5178.236, -601.5394, 397.367, 5.77101, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+56, 24484, 0, 1, 1, 0, -5155.491, -585.8931, 397.3052, 0.734837, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43913 - Brewfest Reveler - Night Elf)
(@CGUID+57, 24484, 0, 1, 1, 0, -5150.194, -581.106, 397.2617, 3.87643, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+58, 24484, 0, 1, 1, 0, -5151.46, -588.4326, 397.4433, 5.72216, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+59, 24484, 0, 1, 1, 0, -5162.544, -600.8759, 398.2272, 4.914649, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+60, 23696, 0, 1, 1, 0, -5136.587, -581.9385, 397.2595, 3.455752, 120, 0, 0), -- Gordok Brew Chief (Area: Dun Morogh)
(@CGUID+61, 23685, 0, 1, 1, 0, -5136.159, -586.4553, 397.3012, 3.577925, 120, 0, 0), -- Gordok Brew Barker (Area: Dun Morogh) (Auras: )
(@CGUID+62, 24484, 0, 1, 1, 0, -5149.818, -605.0708, 398.556, 5.765238, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43908 - Brewfest Reveler - Draenei)
(@CGUID+63, 24484, 0, 1, 1, 0, -5141.182, -594.8916, 397.546, 4.146614, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43908 - Brewfest Reveler - Draenei)
(@CGUID+64, 24484, 0, 1, 1, 0, -5144.808, -600.6024, 398.1843, 3.869892, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43912 - Brewfest Reveler - Human)
(@CGUID+65, 24484, 0, 1, 1, 0, -5155.71, -625.1768, 397.5327, 3.623038, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+66, 24484, 0, 1, 1, 0, -5145.604, -614.9921, 398.3746, 1.043706, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43908 - Brewfest Reveler - Draenei)
(@CGUID+67, 24484, 0, 1, 1, 0, -5142.317, -609.3452, 398.3555, 4.185299, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43908 - Brewfest Reveler - Draenei)
(@CGUID+68, 24484, 0, 1, 1, 0, -5161.049, -619.7647, 397.6951, 5.490935, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43908 - Brewfest Reveler - Draenei)
(@CGUID+69, 24484, 0, 1, 1, 0, -5159.968, -627.4012, 397.3412, 0.4814447, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+70, 23481, 0, 1, 1, 0, -5129.599, -606.1038, 397.4064, 3.054326, 120, 0, 0), -- Keiran Donoghue (Area: Dun Morogh)
(@CGUID+71, 23488, 0, 1, 1, 0, -5122.557, -633.5287, 399.5836, 3.979351, 120, 0, 0), -- Brewfest Crowd (Area: Dun Morogh)
(@CGUID+72, 23703, 0, 1, 1, 0, -5115.206, -612.4749, 402.2297, 2.234021, 120, 0, 0), -- [DND] Brewfest Dark Iron Event Generator (Area: Dun Morogh)
(@CGUID+73, 23488, 0, 1, 1, 0, -5105.744, -624.4401, 412.1684, 2.234021, 120, 0, 0), -- Brewfest Crowd (Area: Dun Morogh)
(@CGUID+74, 24484, 0, 1, 1, 0, -5037.795, -795.8854, 495.2217, 2.488667, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+75, 24484, 0, 1, 1, 0, -5041.38, -789.408, 495.2106, 5.63026, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+76, 24484, 0, 1, 1, 0, -5039.092, -791.158, 495.2118, 5.481099, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+77, 24484, 0, 1, 1, 0, -5038.51, -788.3733, 495.2108, 4.506347, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+78, 24484, 0, 1, 1, 0, -5037.213, -793.1007, 495.2222, 2.339506, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+79, 24484, 0, 1, 1, 0, -5040.083, -794.1354, 495.2119, 5.63026, 120, 0, 0), -- Brewfest Reveler (Area: Dun Morogh) (Auras: 43909 - Brewfest Reveler - Dwarf)
(@CGUID+80, 40441, 0, 1, 1, 0, -4939.448, -937.3698, 503.2399, 0.7679449, 120, 0, 0), -- Battered Brewmaster (Area: Ironforge)
(@CGUID+81, 19148, 0, 1, 1, 0, -4901.802, -958.9554, 501.5429, 1.012291, 120, 0, 0), -- Dwarf Commoner (Area: Ironforge) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+82, 19148, 0, 1, 1, 0, -4900.874, -957.3143, 501.5414, 4.171337, 120, 0, 0), -- Dwarf Commoner (Area: Ironforge) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+83, 19172, 0, 1, 1, 0, -4829.88, -1173.254, 502.2773, 2.495821, 120, 0, 0), -- Gnome Commoner (Area: Ironforge) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+84, 19172, 0, 1, 1, 0, -4831.737, -1172.576, 502.2775, 6.195919, 120, 0, 0), -- Gnome Commoner (Area: Ironforge) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+85, 23698, 0, 1, 1, 0, -5137.566, -626.6026, 397.3508, 1.802031, 120, 0, 0); -- Drunken Brewfest Reveler (Area: Dun Morogh) (Auras: 43905 - Completely Hammered)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+374;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,   195266, 0, 1, 1, 0, -9246.095, -2148.554, 68.11069, 3.159062, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+1,   195266, 0, 1, 1, 0, -9234.066, -2141.21, 70.32656, 1.500983, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+2,   195266, 0, 1, 1, 0, -9225.213, -2139.094, 70.24548, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+3,   195257, 0, 1, 1, 0, -9235.185, -2148.316, 66.44775, 0.122173, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+4,   195259, 0, 1, 1, 0, -9212.752, -2143.257, 65.92102, 4.677484, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+5,   195260, 0, 1, 1, 0, -9217.577, -2145.575, 65.47192, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+6,   195260, 0, 1, 1, 0, -9229.153, -2161.188, 64.88481, 1.466076, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+7,   195260, 0, 1, 1, 0, -9226.616, -2150.386, 64.62093, 1.53589, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+8,   195260, 0, 1, 1, 0, -9212.978, -2149.863, 65.51815, 3.804818, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+9,   195257, 0, 1, 1, 0, -9221.87, -2144.793, 65.65543, 4.747296, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+10,  195253, 0, 1, 1, 0, -9221.179, -2167.573, 70.22387, 4.694937, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Redridge Mountains)
(@OGUID+11,  195264, 0, 1, 1, 0, -9234.33, -2161.907, 65.48932, 4.886924, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+12,  195260, 0, 1, 1, 0, -9222.752, -2159.777, 64.81537, 3.351047, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+13,  195253, 0, 1, 1, 0, -9233.224, -2167.363, 70.25216, 4.694937, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Redridge Mountains)
(@OGUID+14,  195257, 0, 1, 1, 0, -9235.252, -2152.222, 66.45197, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+15,  195253, 0, 1, 1, 0, -9241.352, -2158.479, 70.15424, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Redridge Mountains)
(@OGUID+16,  195264, 0, 1, 1, 0, -9221.364, -2160.02, 64.82926, 2.321287, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+17,  195264, 0, 1, 1, 0, -9226.519, -2148.851, 64.60009, 5.550147, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+18,  195253, 0, 1, 1, 0, -9214.249, -2141.553, 70.16895, 1.553341, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Redridge Mountains)
(@OGUID+19,  195257, 0, 1, 1, 0, -9228.709, -2144.673, 65.5734, 4.81711, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+20,  195259, 0, 1, 1, 0, -9235.771, -2148.469, 66.05069, 3.089183, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+21,  195264, 0, 1, 1, 0, -9228.997, -2162.653, 64.85009, 1.047198, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+22,  195264, 0, 1, 1, 0, -9213.035, -2146.219, 65.51489, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+23,  195264, 0, 1, 1, 0, -9215.894, -2145.814, 65.42332, 1.012289, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+24,  195273, 0, 1, 1, 0, -9245.547, -2160.394, 77.29923, 3.054327, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+25,  195256, 0, 1, 1, 0, -9246.186, -2136.637, 63.93378, 3.612838, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+26,  195253, 0, 1, 1, 0, -9202.232, -2141.319, 70.26682, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Redridge Mountains)
(@OGUID+27,  195255, 0, 1, 1, 0, -9235.648, -2198.986, 81.71343, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Redridge Mountains)
(@OGUID+28,  195259, 0, 1, 1, 0, -9233.308, -2216.292, 68.91117, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+29,  195266, 0, 1, 1, 0, -9243.66, -2211.196, 72.0786, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+30,  195256, 0, 1, 1, 0, -9256.659, -2226.638, 63.93342, 3.089183, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+31,  195266, 0, 1, 1, 0, -9263.477, -2237.091, 68.02573, 3.071766, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+32,  195259, 0, 1, 1, 0, -9213.546, -2224.489, 69.31682, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+33,  195259, 0, 1, 1, 0, -9222.042, -2224.406, 69.23145, 1.500983, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+34,  195266, 0, 1, 1, 0, -9175.255, -2108.599, 92.66118, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+35,  195256, 0, 1, 1, 0, -9234.271, -2077.679, 76.5569, 2.670348, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+36,  195256, 0, 1, 1, 0, -9183.466, -2113.004, 87.78157, 1.692969, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+37,  195256, 0, 1, 1, 0, -9184.45, -2083.873, 87.76208, 3.735006, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+38,  195266, 0, 1, 1, 0, -9180.753, -2086.241, 92.67786, 3.438303, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+39,  195266, 0, 1, 1, 0, -9221.95, -2065.851, 81.47471, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Redridge Mountains)
(@OGUID+40,  195256, 0, 1, 1, 0, -9248.944, -2068.154, 76.47503, 4.729844, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+41,  195256, 0, 1, 1, 0, -9346.304, -2213.286, 61.89773, 1.343901, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+42,  195256, 0, 1, 1, 0, -9282.08, -2301.729, 68.01043, 0.5061446, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+43,  195256, 0, 1, 1, 0, -9280.441, -2269.729, 67.57903, 5.654869, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+44,  195256, 0, 1, 1, 0, -9423.636, -2244.606, 68.45261, 2.722713, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+45,  195256, 0, 1, 1, 0, -9426.249, -2231.333, 68.54076, 3.857183, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+46,  195256, 0, 1, 1, 0, -9411.603, -2259.127, 67.49984, 3.42085, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+47,  195256, 0, 1, 1, 0, -9414.542, -2291.406, 67.65881, 2.530723, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Redridge Mountains)
(@OGUID+48,  195259, 0, 1, 1, 0, -9435.354, -2228.507, 70.02831, 5.358162, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+49,  195259, 0, 1, 1, 0, -9636.213, -2086.488, 62.58199, 1.099556, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+50,  195259, 0, 1, 1, 0, -9589.761, -1928.484, 64.17411, 1.919862, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+51,  195259, 0, 1, 1, 0, -9628.007, -1892.382, 72.56904, 5.078908, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Redridge Mountains)
(@OGUID+52,  195259, 0, 1, 1, 0, -9648.42, -1336.6, 50.6041, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Elwynn Forest)
(@OGUID+53,  195256, 0, 1, 1, 0, -9653.36, -1351.62, 49.9791, 2.199115, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+54,  195256, 0, 1, 1, 0, -9528.31, -1220.07, 47.512, 5.078908, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+55,  195263, 0, 1, 1, 0, -9542.78, -1210.2, 52.139, 2.513274, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+56,  195259, 0, 1, 1, 0, -9536.68, -1208.95, 49.4019, 4.101525, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Elwynn Forest)
(@OGUID+57,  195253, 0, 1, 1, 0, -9530.54, -1220.03, 51.8579, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Elwynn Forest)
(@OGUID+58,  195256, 0, 1, 1, 0, -9527.63, -694.899, 61.8202, 0.7155849, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+59,  195263, 0, 1, 1, 0, -9537.14, -707.063, 66.1065, 0.8203033, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+60,  195253, 0, 1, 1, 0, -9547.04, -733.826, 98.1384, 5.445428, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Elwynn Forest)
(@OGUID+61,  195259, 0, 1, 1, 0, -9539.26, -700.099, 68.9415, 0.7155849, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Elwynn Forest)
(@OGUID+62,  195263, 0, 1, 1, 0, -9545.9, -697.432, 66.2059, 0.7155849, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+63,  195253, 0, 1, 1, 0, -9545.47, -705.538, 98.157, 0.7504908, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Elwynn Forest)
(@OGUID+64,  195256, 0, 1, 1, 0, -9532.86, -689.003, 61.8336, 0.802851, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+65,  195266, 0, 1, 1, 0, -9382.36, -82.4038, 68.335, 4.188792, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Elwynn Forest)
(@OGUID+66,  195256, 0, 1, 1, 0, -9378.76, -86.2716, 63.6306, 3.543024, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Elwynn Forest)
(@OGUID+67,  186717, 0, 1, 1, 0, -9128.238, 325.459, 93.50195, 1.850049, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+68,  186717, 0, 1, 1, 0, -9137.063, 372.1153, 90.57259, 1.466076, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+69,  186717, 0, 1, 1, 0, -9150.724, 357.4999, 89.90228, 2.809975, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+70,  186717, 0, 1, 1, 0, -9114.491, 342.7754, 93.66718, 3.001947, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+71,  186717, 0, 1, 1, 0, -9124.605, 357.9988, 92.98186, 3.909541, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+72,  186717, 0, 1, 1, 0, -9137.364, 389.8789, 90.97507, 0.3665176, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+73,  186717, 0, 1, 1, 0, -9184.333, 334.9997, 82.31686, 5.026549, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Elwynn Forest)
(@OGUID+74,  180037, 0, 1, 1, 0, -9117.236, 322.8356, 93.23306, 0.7155849, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Elwynn Forest)
(@OGUID+75,  180037, 0, 1, 1, 0, -9116.251, 325.7961, 93.18729, 2.18166, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Elwynn Forest)
(@OGUID+76,  186257, 0, 1, 1, 0, -9123.091, 321.4732, 93.44196, 4.904376, 0, 0, 0, 1, 120, 255, 1), -- Gordok Festive Wagon (Area: Elwynn Forest)
(@OGUID+77,  180037, 0, 1, 1, 0, -9120.161, 323.513, 93.30685, 1.797689, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Elwynn Forest)
(@OGUID+78,  195265, 0, 1, 1, 0, -9072.81, 411.155, 92.7449, 0.2268925, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+79,  195254, 0, 1, 1, 0, -9065.88, 414.826, 98.7892, 2.251473, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+80,  180037, 0, 1, 1, 0, -9111.789, 345.3135, 93.52122, 0.2967052, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Elwynn Forest)
(@OGUID+81,  178666, 0, 1, 1, 0, -9109.536, 338.4199, 93.47884, 1.413715, 0, 0, 0, 1, 120, 255, 1), -- Gypsy Wagon (Area: Elwynn Forest)
(@OGUID+82,  178666, 0, 1, 1, 0, -9114.387, 351.52, 93.52726, 2.164206, 0, 0, 0, 1, 120, 255, 1), -- Gypsy Wagon (Area: Elwynn Forest)
(@OGUID+83,  195265, 0, 1, 1, 0, -9043.32, 430.911, 93.2879, 2.303831, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+84,  195265, 0, 1, 1, 0, -9089.38, 431.97, 92.8513, 5.445428, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+85,  195265, 0, 1, 1, 0, -9050.57, 424.715, 93.285, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+86,  195254, 0, 1, 1, 0, -9083.63, 437.943, 98.252, 5.462882, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+87,  195255, 0, 1, 1, 0, -9062.11, 436.523, 111.193, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+88,  186259, 0, 1, 1, 0, -9113.325, 332.2217, 93.15086, 5.567601, 0, 0, 0, 1, 120, 255, 1), -- Thunderbrew Festive Wagon (Area: Elwynn Forest)
(@OGUID+89,  186260, 0, 1, 1, 0, -9120.435, 356.5367, 93.25022, 0.6806767, 0, 0, 0, 1, 120, 255, 1), -- Barleybrew Festive Wagon (Area: Elwynn Forest)
(@OGUID+90,  195265, 0, 1, 1, 0, -9063.14, 456.014, 93.2763, 5.305802, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+91,  195265, 0, 1, 1, 0, -9071.21, 449.92, 93.2858, 0.3316107, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Elwynn Forest)
(@OGUID+92,  195265, 0, 1, 1, 0, -8973.23, 491.104, 97.0423, 2.076939, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Stormwind City)
(@OGUID+93,  195265, 0, 1, 1, 0, -9018.02, 485.073, 97.1019, 5.427975, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Stormwind City)
(@OGUID+94,  195265, 0, 1, 1, 0, -8987.81, 509.179, 97.0711, 5.480334, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Stormwind City)
(@OGUID+95,  195265, 0, 1, 1, 0, -9003.55, 467.036, 97.1128, 2.129301, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Stormwind City)
(@OGUID+96,  186717, 0, 1, 1, 0, -5644.706, -477.0167, 396.7484, 4.607672, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+97,  186717, 0, 1, 1, 0, -5620.104, -473.0208, 396.9604, 6.03884, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+98,  186717, 0, 1, 1, 0, -5610.049, -457.4845, 405.3016, 5.916668, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+99,  186717, 0, 1, 1, 0, -5337.041, -542.3473, 393.6581, 1.396262, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+100, 195256, 0, 1, 1, 0, -5643.28, -503.156, 396.681, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+101, 195260, 0, 1, 1, 0, -5654.715, -502.6059, 398.2567, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+102, 195260, 0, 1, 1, 0, -5606.694, -532.3544, 400.5222, 1.500983, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+103, 195260, 0, 1, 1, 0, -5606.856, -527.5001, 402.5878, 3.316144, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+104, 195253, 0, 1, 1, 0, -5596.977, -512.8995, 411.5967, 1.553341, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+105, 195266, 0, 1, 1, 0, -5597.3, -532.3472, 403.0714, 1.500983, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Dun Morogh)
(@OGUID+106, 195253, 0, 1, 1, 0, -5604.448, -512.7601, 411.5909, 1.53589, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+107, 195259, 0, 1, 1, 0, -5608.684, -529.5765, 401.0659, 6.248279, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+108, 195253, 0, 1, 1, 0, -5612.138, -518.6824, 411.9816, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+109, 195259, 0, 1, 1, 0, -5608.479, -521.5131, 401.212, 6.265733, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+110, 195260, 0, 1, 1, 0, -5604.241, -532.3936, 400.5223, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+111, 195259, 0, 1, 1, 0, -5607.962, -525.4995, 402.7486, 0, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+112, 195263, 0, 1, 1, 0, -5592.182, -532.5336, 401.91, 1.553341, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+113, 195260, 0, 1, 1, 0, -5594.529, -525.8619, 400.5474, 0.03490625, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+114, 195253, 0, 1, 1, 0, -5593.03, -509.2291, 411.6137, 3.106652, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+115, 195260, 0, 1, 1, 0, -5600.698, -525.1803, 400.5451, 6.213374, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+116, 195264, 0, 1, 1, 0, -5584.555, -533.0618, 404.4201, 0.8726639, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+117, 195264, 0, 1, 1, 0, -5584.568, -528.3982, 401.6423, 0.2967052, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+118, 195263, 0, 1, 1, 0, -5576.637, -514.9565, 405.1905, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+119, 195264, 0, 1, 1, 0, -5586.716, -528.2309, 400.2072, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+120, 195253, 0, 1, 1, 0, -5582.827, -503.6929, 411.7398, 1.553341, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+121, 195256, 0, 1, 1, 0, -5605.661, -489.755, 397.5626, 1.797689, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+122, 195260, 0, 1, 1, 0, -5591.76, -508.4743, 405.0105, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Dun Morogh)
(@OGUID+123, 195253, 0, 1, 1, 0, -5576.134, -520.7516, 411.7462, 6.265733, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+124, 195259, 0, 1, 1, 0, -5590.899, -513.9167, 405.7715, 1.658062, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+125, 195259, 0, 1, 1, 0, -5579.731, -525.0503, 404.4669, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+126, 195253, 0, 1, 1, 0, -5575.937, -509.4737, 411.7925, 6.265733, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+127, 186709, 0, 1, 1, 0, -5613.839, -470.8222, 398.039, 4.747296, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+128, 186709, 0, 1, 1, 0, -5615.797, -470.9076, 398.0607, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+129, 186709, 0, 1, 1, 0, -5617.754, -470.9753, 398.0358, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+130, 195256, 0, 1, 1, 0, -5568.507, -501.3629, 402.8596, 1.362257, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+131, 186709, 0, 1, 1, 0, -5612.898, -470.8262, 399.2884, 4.747296, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+132, 186709, 0, 1, 1, 0, -5611.944, -470.736, 398.0418, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+133, 186709, 0, 1, 1, 0, -5616.769, -470.9492, 399.2328, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+134, 195259, 0, 1, 1, 0, -5593.129, -489.4366, 398.3633, 1.53589, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+135, 186717, 0, 1, 1, 0, -5236.781, -635.8247, 421.8013, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+136, 186717, 0, 1, 1, 0, -5252.011, -477.2503, 386.6239, 4.904376, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+137, 186681, 0, 1, 1, 0, -5190.952, -586.5555, 397.3453, 0.1382307, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Dun Morogh)
(@OGUID+138, 186252, 0, 1, 1, 0, -5192.862, -615.2213, 398.0651, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+139, 186229, 0, 1, 1, 0, -5191.231, -561.2604, 397.1762, 5.183629, 0, 0, 0, 1, 120, 255, 1), -- BREWFEST (Area: Dun Morogh)
(@OGUID+140, 186717, 0, 1, 1, 0, -5214.628, -514.1525, 389.7317, 1.745327, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+141, 186717, 0, 1, 1, 0, -5197.209, -505.3072, 388.5976, 2.007128, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+142, 186717, 0, 1, 1, 0, -5205.448, -479.0623, 389.1464, 2.094393, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+143, 186717, 0, 1, 1, 0, -5207.184, -535.7542, 393.7946, 1.780234, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+144, 195256, 0, 1, 1, 0, -5535.453, -476.9323, 398.0912, 5.619962, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+145, 186717, 0, 1, 1, 0, -5189.3, -525.5062, 392.5254, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+146, 186717, 0, 1, 1, 0, -5218.609, -491.6126, 387.8888, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+147, 186229, 0, 1, 1, 0, -5219.014, -475.2069, 386.6611, 5.532695, 0, 0, 0, 1, 120, 255, 1), -- BREWFEST (Area: Dun Morogh)
(@OGUID+148, 186252, 0, 1, 1, 0, -5197.939, -587.6623, 398.3996, 1.710422, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+149, 186252, 0, 1, 1, 0, -5195.895, -601.4579, 398.6494, 1.745327, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+150, 186252, 0, 1, 1, 0, -5197.76, -573.3922, 398.4808, 4.537859, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+151, 180749, 0, 1, 1, 0, -5214.482, -514.3778, 389.7595, 0.7679439, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Dun Morogh)
(@OGUID+152, 186680, 0, 1, 1, 0, -5179.604, -543.4095, 396.9182, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Canopy (Area: Dun Morogh)
(@OGUID+153, 186717, 0, 1, 1, 0, -5180.2, -615.9891, 397.1762, 0.4188786, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+154, 186252, 0, 1, 1, 0, -5185.058, -627.0389, 397.9193, 5.585054, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+155, 180749, 0, 1, 1, 0, -5182.854, -539.3351, 397.0353, 4.729844, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Dun Morogh)
(@OGUID+156, 186252, 0, 1, 1, 0, -5170.272, -549.3871, 397.6137, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+157, 186252, 0, 1, 1, 0, -5170.992, -537.0357, 398.1315, 0.087266, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+158, 186252, 0, 1, 1, 0, -5180.265, -485.5065, 388.4359, 1.745327, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+159, 186252, 0, 1, 1, 0, -5185.947, -492.8411, 387.9589, 3.194002, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+160, 186252, 0, 1, 1, 0, -5188.662, -480.1567, 388.4914, 3.42085, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+161, 186717, 0, 1, 1, 0, -5199.622, -432.8177, 390.4116, 2.722713, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+162, 186680, 0, 1, 1, 0, -5194.545, -487.2587, 387.5414, 3.281239, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Canopy (Area: Dun Morogh)
(@OGUID+163, 186682, 0, 1, 1, 0, -5186.544, -610.6227, 397.1762, 0.2967052, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Beer Tent (Area: Dun Morogh)
(@OGUID+164, 180749, 0, 1, 1, 0, -5182.361, -613.8264, 397.1762, 3.892087, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Dun Morogh)
(@OGUID+165, 195266, 0, 1, 1, 0, -5519.259, -663.9238, 403.0417, 0.4014249, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Dun Morogh)
(@OGUID+166, 180749, 0, 1, 1, 0, -5141.325, -578.4202, 397.1762, 2.426008, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Dun Morogh)
(@OGUID+167, 180749, 0, 1, 1, 0, -5127.931, -598.033, 397.2354, 2.949595, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Dun Morogh)
(@OGUID+168, 186252, 0, 1, 1, 0, -5155.841, -561.3016, 398.2734, 2.600535, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+169, 186252, 0, 1, 1, 0, -5127.788, -576.9871, 398.329, 5.654869, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+170, 186252, 0, 1, 1, 0, -5144.438, -569.3953, 398.4123, 5.619962, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+171, 186681, 0, 1, 1, 0, -5125.849, -606.7365, 397.5661, 2.967041, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Dun Morogh)
(@OGUID+172, 186252, 0, 1, 1, 0, -5167.182, -639.3504, 398.3012, 5.829401, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+173, 186173, 0, 1, 1, 0, -5133.704, -621.1421, 398.6569, 0.8726639, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Keg Breakable (Area: Dun Morogh)
(@OGUID+174, 186252, 0, 1, 1, 0, -5167.689, -553.475, 398.4748, 5.794494, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+175, 186252, 0, 1, 1, 0, -5162.599, -542.8001, 397.6345, 4.852017, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+176, 186717, 0, 1, 1, 0, -5134.115, -586.7226, 397.1762, 3.47321, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+177, 186682, 0, 1, 1, 0, -5147.898, -635.9807, 397.1762, 1.745327, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Beer Tent (Area: Dun Morogh)
(@OGUID+178, 186714, 0, 1, 1, 0, -5131.425, -622.4551, 396.1465, 1.623156, 0, 0, 0, 1, 120, 255, 1), -- Shoutbox (Area: Dun Morogh)
(@OGUID+179, 186717, 0, 1, 1, 0, -5139.138, -632.3252, 397.1794, 1.692969, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+180, 186717, 0, 1, 1, 0, -5191.74, -736.3221, 447.2843, 0.8377575, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+181, 186717, 0, 1, 1, 0, -5137.491, -622.2783, 397.3992, 2.33874, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+182, 186682, 0, 1, 1, 0, -5136.073, -579.4153, 397.1762, 3.874631, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Beer Tent (Area: Dun Morogh)
(@OGUID+183, 186252, 0, 1, 1, 0, -5130.747, -633.7814, 398.3118, 0.9773831, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+184, 186252, 0, 1, 1, 0, -5154.252, -644.3858, 398.2596, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+185, 186252, 0, 1, 1, 0, -5141.08, -642.6694, 398.0721, 0.4537851, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+186, 186681, 0, 1, 1, 0, -5175.351, -631.7859, 397.1762, 0.9948372, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Dun Morogh)
(@OGUID+187, 186681, 0, 1, 1, 0, -5160.816, -565.0238, 397.1762, 3.752462, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Dun Morogh)
(@OGUID+188, 186717, 0, 1, 1, 0, -5132.811, -616.4373, 397.3624, 2.495818, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+189, 186252, 0, 1, 1, 0, -5126.319, -586.1402, 398.2943, 0.7330382, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+190, 186252, 0, 1, 1, 0, -5123.158, -594.8695, 398.1762, 3.769912, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+191, 195256, 0, 1, 1, 0, -5483.444, -669.2147, 392.698, 0.2268925, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+192, 186252, 0, 1, 1, 0, -5124.67, -620.3724, 398.9654, 1.378809, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Dun Morogh)
(@OGUID+193, 186717, 0, 1, 1, 0, -5091.119, -734.7433, 469.9098, 4.799657, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+194, 195259, 0, 1, 1, 0, -5357.044, -528.766, 392.5752, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Dun Morogh)
(@OGUID+195, 186680, 0, 1, 1, 0, -5033.799, -789.7986, 495.1776, 3.508117, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Canopy (Area: Dun Morogh)
(@OGUID+196, 186189, 0, 1, 1, 0, -5180.918, -619.2928, 398.2873, 6.19592, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+197, 180698, 0, 1, 1, 0, -5180.746, -618.4632, 397.1762, 0.4014249, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+198, 179973, 0, 1, 1, 0, -5181.609, -624.9522, 397.1762, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Inn Barrel (Area: Dun Morogh)
(@OGUID+199, 179973, 0, 1, 1, 0, -5182.578, -623.7708, 397.1762, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- Inn Barrel (Area: Dun Morogh)
(@OGUID+200, 179973, 0, 1, 1, 0, -5183.147, -625.1269, 397.1762, 5.166176, 0, 0, 0, 1, 120, 255, 1), -- Inn Barrel (Area: Dun Morogh)
(@OGUID+201, 179970, 0, 1, 1, 0, -5177.422, -624.6458, 397.1762, 3.996807, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+202, 179970, 0, 1, 1, 0, -5176.669, -624.4911, 397.1762, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+203, 179970, 0, 1, 1, 0, -5177.397, -623.7738, 397.1762, 4.049168, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+204, 180353, 0, 1, 1, 0, -5171, -628.9365, 397.1762, 2.076939, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+205, 180353, 0, 1, 1, 0, -5174.59, -626.7505, 397.1762, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+206, 180353, 0, 1, 1, 0, -5178.735, -620.2941, 397.1762, 0.9075702, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+207, 186189, 0, 1, 1, 0, -5181.279, -618.0822, 398.2873, 3.892087, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+208, 186189, 0, 1, 1, 0, -5180.274, -618.2279, 398.2873, 5.393069, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+209, 179970, 0, 1, 1, 0, -5177.139, -625.7251, 397.1762, 0.2268925, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+210, 179970, 0, 1, 1, 0, -5178.15, -625.577, 397.1762, 0.3665176, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+211, 179970, 0, 1, 1, 0, -5178.94, -624.4315, 397.1762, 1.675514, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+212, 179970, 0, 1, 1, 0, -5178.793, -623.5281, 397.1762, 2.408554, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+213, 179970, 0, 1, 1, 0, -5179.821, -626.6215, 397.1762, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+214, 179970, 0, 1, 1, 0, -5179.335, -625.5864, 397.1762, 0.1745321, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Dun Morogh)
(@OGUID+215, 186189, 0, 1, 1, 0, -5179.868, -618.8417, 398.2873, 1.361356, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+216, 180353, 0, 1, 1, 0, -5186.012, -588.507, 397.3098, 4.274661, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+217, 180698, 0, 1, 1, 0, -5188.103, -592.1146, 397.1893, 0.01605623, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+218, 186189, 0, 1, 1, 0, -5187.387, -592.6702, 398.2692, 0.7665493, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+219, 186189, 0, 1, 1, 0, -5187.264, -591.6042, 398.2834, 1.551946, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+220, 186183, 0, 1, 1, 0, -5187.228, -599.7787, 397.1762, 0.01745246, 0, 0, 0, 1, 120, 255, 1), -- Barleybrew Festive Keg (Area: Dun Morogh)
(@OGUID+221, 186189, 0, 1, 1, 0, -5187.271, -592.2188, 398.2967, 5.601112, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+222, 180353, 0, 1, 1, 0, -5186.785, -583.3924, 397.2424, 2.68641, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+223, 186184, 0, 1, 1, 0, -5160.053, -632.632, 397.1778, 1.396262, 0, 0, 0, 1, 120, 255, 1), -- Thunderbrew Festive Keg (Area: Dun Morogh)
(@OGUID+224, 180353, 0, 1, 1, 0, -5144.526, -630.9318, 397.201, 5.93412, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+225, 180353, 0, 1, 1, 0, -5138.65, -623.0335, 397.3982, 1.483528, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+226, 180698, 0, 1, 1, 0, -5139.809, -631.2952, 397.1842, 0.2443456, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+227, 186189, 0, 1, 1, 0, -5140.135, -631.197, 398.3177, 4.293513, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+228, 186189, 0, 1, 1, 0, -5139.533, -630.5913, 398.3156, 1.396262, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+229, 186189, 0, 1, 1, 0, -5140.642, -630.7866, 398.3101, 2.984498, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+230, 180353, 0, 1, 1, 0, -5192.166, -559.8302, 397.1762, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+231, 186189, 0, 1, 1, 0, -5139.092, -631.3373, 398.3243, 3.455756, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+232, 180037, 0, 1, 1, 0, -5173.12, -560.5593, 397.1762, 6.126106, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+233, 180037, 0, 1, 1, 0, -5170.845, -563.2278, 397.1762, 0.7155849, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+234, 180353, 0, 1, 1, 0, -5166.728, -566.1479, 397.1762, 1.53589, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+235, 180353, 0, 1, 1, 0, -5182.542, -554.7311, 397.1762, 3.47321, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+236, 195266, 0, 1, 1, 0, -5480.081, -461.8063, 401.4652, 6.003934, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Dun Morogh)
(@OGUID+237, 195256, 0, 1, 1, 0, -5461.149, -479.1237, 396.6999, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+238, 195253, 0, 1, 1, 0, -5578.943, -461.7432, 409.891, 4.694937, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Dun Morogh)
(@OGUID+239, 195263, 0, 1, 1, 0, -5573.334, -461.3463, 404.8426, 4.694937, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+240, 195256, 0, 1, 1, 0, -5588.756, -425.2837, 397.3254, 5.166176, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+241, 195263, 0, 1, 1, 0, -5585.392, -461.5064, 404.8497, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+242, 195263, 0, 1, 1, 0, -5580.912, -418.4516, 400.419, 4.956738, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Dun Morogh)
(@OGUID+243, 186189, 0, 1, 1, 0, -5212.133, -508.7171, 389.8518, 6.265733, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+244, 180698, 0, 1, 1, 0, -5212.578, -509.3127, 388.7388, 0.1745321, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+245, 180353, 0, 1, 1, 0, -5219.924, -485.5978, 387.8988, 1.343901, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+246, 180353, 0, 1, 1, 0, -5214.958, -510.7971, 389.3493, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+247, 186189, 0, 1, 1, 0, -5213.169, -508.8343, 389.8408, 0.6108634, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+248, 186189, 0, 1, 1, 0, -5211.824, -509.6712, 389.8385, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+249, 180353, 0, 1, 1, 0, -5208.733, -531.9574, 392.7095, 4.450591, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+250, 180353, 0, 1, 1, 0, -5198.776, -502.6649, 388.4015, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+251, 180353, 0, 1, 1, 0, -5189.862, -523.3077, 391.7257, 2.617989, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+252, 180037, 0, 1, 1, 0, -5185.292, -491.15, 386.5858, 0.1047193, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+253, 186189, 0, 1, 1, 0, -5193.02, -516.2057, 390.9093, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+254, 186709, 0, 1, 1, 0, -5197.474, -484.7535, 389.188, 3.351047, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+255, 186709, 0, 1, 1, 0, -5196.546, -481.3118, 389.2609, 1.867502, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+256, 186709, 0, 1, 1, 0, -5198.5, -481.9359, 389.5273, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Dun Morogh)
(@OGUID+257, 180353, 0, 1, 1, 0, -5206.835, -475.9671, 388.5916, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+258, 180353, 0, 1, 1, 0, -5198.233, -490.8853, 388.2694, 1.797689, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+259, 180698, 0, 1, 1, 0, -5192.298, -516.5252, 389.8175, 3.612838, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+260, 186189, 0, 1, 1, 0, -5192.268, -515.6999, 390.9125, 3.001947, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+261, 180353, 0, 1, 1, 0, -5183.63, -540.1546, 397.0719, 0.05235888, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+262, 180037, 0, 1, 1, 0, -5181.629, -485.5835, 387.3477, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+263, 179975, 0, 1, 1, 0, -5181.714, -489.2394, 386.8131, 0.5061446, 0, 0, 0, 1, 120, 255, 1), -- Water Trough Small (Area: Dun Morogh)
(@OGUID+264, 186189, 0, 1, 1, 0, -5179.162, -540.8138, 398.1618, 5.707228, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+265, 180037, 0, 1, 1, 0, -5165.252, -540.4322, 397.1762, 4.869471, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+266, 180698, 0, 1, 1, 0, -5179.37, -540.6351, 397.0732, 0.157079, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+267, 180037, 0, 1, 1, 0, -5164.709, -545.2327, 397.1762, 1.134463, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+268, 186189, 0, 1, 1, 0, -5180.276, -541.2448, 398.183, 4.031712, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+269, 186189, 0, 1, 1, 0, -5179.199, -545.677, 398.2782, 1.797689, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+270, 186189, 0, 1, 1, 0, -5178.812, -545.6241, 398.2783, 2.129301, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+271, 186189, 0, 1, 1, 0, -5179.208, -540.1765, 398.1736, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+272, 186189, 0, 1, 1, 0, -5179.621, -545.9332, 398.279, 3.351047, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+273, 186189, 0, 1, 1, 0, -5179.159, -546.7122, 398.2794, 6.213374, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+274, 186189, 0, 1, 1, 0, -5179.625, -541.3425, 398.194, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+275, 186189, 0, 1, 1, 0, -5179.922, -540.0702, 398.1999, 1.012289, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+276, 180353, 0, 1, 1, 0, -5182.451, -546.9822, 397.1748, 4.537859, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+277, 180698, 0, 1, 1, 0, -5179.068, -545.7936, 397.1751, 3.281239, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+278, 186189, 0, 1, 1, 0, -5178.882, -546.3141, 398.2861, 3.42085, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+279, 180353, 0, 1, 1, 0, -5173.908, -559.1235, 397.1762, 4.415683, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+280, 180698, 0, 1, 1, 0, -5158.652, -571.771, 397.1762, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+281, 186189, 0, 1, 1, 0, -5158.591, -570.8616, 398.2729, 3.368496, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+282, 186189, 0, 1, 1, 0, -5158.417, -571.9476, 398.2943, 0.2967052, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+283, 186189, 0, 1, 1, 0, -5158.822, -572.2585, 398.2873, 3.159062, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+284, 186189, 0, 1, 1, 0, -5157.938, -571.9861, 398.2873, 0.6632232, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+285, 186189, 0, 1, 1, 0, -5159.3, -571.6622, 398.2873, 0.4014249, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+286, 186185, 0, 1, 1, 0, -5145.747, -575.667, 397.1762, 3.996807, 0, 0, 0, 1, 120, 255, 1), -- Gordok Festive Keg (Area: Dun Morogh)
(@OGUID+287, 186189, 0, 1, 1, 0, -5132.596, -588.2156, 398.2805, 1.500983, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+288, 186189, 0, 1, 1, 0, -5132.92, -587.8846, 398.2805, 4.485497, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+289, 186189, 0, 1, 1, 0, -5132.505, -587.1273, 398.2874, 1.483528, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+290, 180698, 0, 1, 1, 0, -5132.599, -588.1033, 397.1762, 0.383971, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+291, 186189, 0, 1, 1, 0, -5133.111, -588.8533, 398.2806, 1.361356, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+292, 180353, 0, 1, 1, 0, -5131.588, -591.271, 397.1766, 2.164206, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+293, 186189, 0, 1, 1, 0, -5130.064, -599.8104, 398.3108, 5.427975, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+294, 180698, 0, 1, 1, 0, -5130.184, -600.5275, 397.2235, 3.438303, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+295, 180037, 0, 1, 1, 0, -5117.444, -580.4518, 397.5432, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+296, 180006, 0, 1, 1, 0, -5118.044, -583.9196, 397.2173, 4.502952, 0, 0, 0, 1, 120, 255, 1), -- Outhouse (Area: Dun Morogh)
(@OGUID+297, 180353, 0, 1, 1, 0, -5129.314, -598.0792, 397.1857, 0.2792516, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+298, 186189, 0, 1, 1, 0, -5129.982, -600.626, 398.3268, 1.169369, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+299, 186189, 0, 1, 1, 0, -5130.73, -600.9566, 398.3385, 0.6283169, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+300, 186189, 0, 1, 1, 0, -5131.017, -600.2695, 398.3386, 2.268925, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+301, 180353, 0, 1, 1, 0, -5130.941, -608.9923, 397.4081, 3.403396, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+302, 180006, 0, 1, 1, 0, -5112.979, -587.9803, 397.2141, 3.595379, 0, 0, 0, 1, 120, 255, 1), -- Outhouse (Area: Dun Morogh)
(@OGUID+303, 180037, 0, 1, 1, 0, -5112.556, -591.7613, 397.1787, 6.143561, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Dun Morogh)
(@OGUID+304, 180006, 0, 1, 1, 0, -5114.941, -585.425, 397.2218, 3.979355, 0, 0, 0, 1, 120, 255, 1), -- Outhouse (Area: Dun Morogh)
(@OGUID+305, 180353, 0, 1, 1, 0, -5131.87, -614.546, 397.3651, 4.34587, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Dun Morogh)
(@OGUID+306, 186717, 0, 1, 1, 0, -4920.193, -940.244, 501.5717, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+307, 186717, 0, 1, 1, 0, -4905.156, -956.5208, 501.4696, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Dun Morogh)
(@OGUID+308, 180698, 0, 1, 1, 0, -5034.881, -790.3542, 495.1668, 5.009095, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+309, 180698, 0, 1, 1, 0, -5059.743, -812.6451, 495.1413, 5.969027, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Dun Morogh)
(@OGUID+310, 186189, 0, 1, 1, 0, -5035.438, -791.1423, 496.2585, 4.97419, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+311, 186189, 0, 1, 1, 0, -5035.659, -790.0628, 496.2695, 2.897245, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Dun Morogh)
(@OGUID+312, 195256, 0, 1, 1, 0, -4980.035, -865.8755, 501.6593, 3.735006, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+313, 195256, 0, 1, 1, 0, -5000.161, -841.3087, 501.6593, 3.822273, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+314, 195256, 0, 1, 1, 0, -4990.289, -853.3428, 501.6593, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+315, 195256, 0, 1, 1, 0, -4997.849, -880.6901, 501.6593, 0.7155849, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+316, 195256, 0, 1, 1, 0, -5018.228, -855.9774, 501.6593, 0.6806767, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+317, 195256, 0, 1, 1, 0, -5008.323, -868.1884, 501.6593, 0.7679439, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+318, 195255, 0, 1, 1, 0, -4971.149, -937.866, 510.3488, 5.532695, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+319, 195255, 0, 1, 1, 0, -4928.487, -902.7635, 510.4512, 5.288348, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+320, 195255, 0, 1, 1, 0, -5003.481, -983.3287, 510.498, 5.794494, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+321, 195255, 0, 1, 1, 0, -4878.06, -879.947, 510.2419, 5.026549, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+322, 195264, 0, 1, 1, 0, -4905.373, -979.2542, 503.5185, 5.742135, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+323, 195264, 0, 1, 1, 0, -4900.674, -975.4097, 503.4907, 2.705255, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+324, 195266, 0, 1, 1, 0, -4899.028, -982.3143, 510.7769, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+325, 195273, 0, 1, 1, 0, -4888.821, -994.7379, 510.0488, 2.321287, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Ironforge)
(@OGUID+326, 186717, 0, 1, 1, 0, -4649.492, -972.0113, 501.6598, 5.410522, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+327, 186717, 0, 1, 1, 0, -4673.023, -935.6511, 501.659, 2.234018, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+328, 186717, 0, 1, 1, 0, -4969.789, -1222.796, 501.6696, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+329, 186717, 0, 1, 1, 0, -4983.488, -1204.278, 501.6689, 2.321287, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+330, 195264, 0, 1, 1, 0, -4886.383, -993.6835, 504.7578, 2.321287, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+331, 195264, 0, 1, 1, 0, -4890.226, -996.7995, 504.7578, 0.4188786, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+332, 195264, 0, 1, 1, 0, -4895.289, -1001.13, 504.7578, 3.263772, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+333, 195273, 0, 1, 1, 0, -4879.835, -987.3299, 509.9829, 2.146753, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Ironforge)
(@OGUID+334, 195273, 0, 1, 1, 0, -4897.691, -1002.05, 510.0543, 2.076939, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Ironforge)
(@OGUID+335, 186717, 0, 1, 1, 0, -4678.11, -968.1516, 501.6593, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+336, 195266, 0, 1, 1, 0, -4880.097, -957.7726, 509.6276, 1.937312, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+337, 186717, 0, 1, 1, 0, -4960.084, -1200.375, 501.6594, 0.6806767, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+338, 186717, 0, 1, 1, 0, -4712.871, -1213.871, 501.6593, 2.35619, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+339, 195266, 0, 1, 1, 0, -4974.479, -1033.467, 509.735, 2.775069, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+340, 195264, 0, 1, 1, 0, -4899.348, -1004.479, 504.7578, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+341, 186717, 0, 1, 1, 0, -4698.129, -1246.366, 501.6593, 3.892087, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+342, 195264, 0, 1, 1, 0, -4877.422, -986.3079, 504.7578, 5.707228, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+343, 195260, 0, 1, 1, 0, -4877.751, -999.5267, 506.9579, 3.228859, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Ironforge)
(@OGUID+344, 195260, 0, 1, 1, 0, -4888.352, -1008.27, 506.9579, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Ironforge)
(@OGUID+345, 195260, 0, 1, 1, 0, -4875.534, -997.696, 506.9579, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Ironforge)
(@OGUID+346, 195260, 0, 1, 1, 0, -4885.095, -1005.571, 506.9579, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Ironforge)
(@OGUID+347, 195264, 0, 1, 1, 0, -4881.061, -989.3226, 504.7578, 5.253442, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Ironforge)
(@OGUID+348, 186717, 0, 1, 1, 0, -4675.359, -1228.174, 501.6593, 0.6632232, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Ironforge)
(@OGUID+349, 195266, 0, 1, 1, 0, -4798.366, -908.9757, 503.2498, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+350, 195266, 0, 1, 1, 0, -4765.774, -913.3871, 508.2345, 1.326448, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+351, 195255, 0, 1, 1, 0, -4700.935, -958.9014, 510.2951, 0.8203033, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+352, 195266, 0, 1, 1, 0, -4707.566, -948.4097, 509.8717, 0.9075702, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+353, 195256, 0, 1, 1, 0, -4623.986, -917.6334, 501.063, 0.6981314, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+354, 195259, 0, 1, 1, 0, -4630.104, -928.945, 506.1224, 0.7330382, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Small - Brewfest (Area: Ironforge)
(@OGUID+355, 195256, 0, 1, 1, 0, -4618.024, -925.1197, 501.0621, 0.7853968, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+356, 195255, 0, 1, 1, 0, -4672.899, -992.939, 510.192, 0.5759573, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+357, 195256, 0, 1, 1, 0, -4609.135, -905.3917, 501.0677, 3.909541, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+358, 195256, 0, 1, 1, 0, -4602.831, -912.7859, 501.0661, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Ironforge)
(@OGUID+359, 195266, 0, 1, 1, 0, -4601.875, -1010.215, 509.9108, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+360, 195266, 0, 1, 1, 0, -4591.766, -999.4636, 508.2067, 3.438303, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+361, 195266, 0, 1, 1, 0, -4612.878, -1093.26, 509.6406, 3.054327, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+362, 195266, 0, 1, 1, 0, -4614.037, -1114.479, 509.55, 3.33359, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+363, 195266, 0, 1, 1, 0, -4691.635, -1183.896, 509.9148, 5.550147, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+364, 195255, 0, 1, 1, 0, -4684.716, -1205.307, 510.4501, 2.35619, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+365, 195266, 0, 1, 1, 0, -4732.766, -1146.49, 507.5392, 2.652894, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+366, 195255, 0, 1, 1, 0, -4720.983, -1235.199, 510.4226, 2.129301, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+367, 195266, 0, 1, 1, 0, -4804.957, -1180.351, 510.4589, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+368, 195255, 0, 1, 1, 0, -4931.615, -1206.357, 509.6404, 3.961899, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+369, 195266, 0, 1, 1, 0, -4927.707, -1279.47, 509.7956, 2.652894, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+370, 195255, 0, 1, 1, 0, -4959.707, -1172.347, 509.8299, 3.700105, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Large - Brewfest (Area: Ironforge)
(@OGUID+371, 195266, 0, 1, 1, 0, -4989.778, -1117.278, 508.1858, 3.316144, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+372, 195266, 0, 1, 1, 0, -5041.653, -1166.186, 508.2274, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+373, 195266, 0, 1, 1, 0, -5030.981, -1153.903, 509.7602, 5.009095, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Ironforge)
(@OGUID+374, 195266, 0, 1, 1, 0, -5017.75, -1125.038, 509.9572, 0.1919852, 0, 0, 0, 1, 120, 255, 1); -- Hanging; Streamer - Brewfest (Area: Ironforge)

DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+85;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, @CGUID+0), 
(24, @CGUID+1), 
(24, @CGUID+2), 
(24, @CGUID+3), 
(24, @CGUID+4), 
(24, @CGUID+5), 
(24, @CGUID+6), 
(24, @CGUID+7), 
(24, @CGUID+8), 
(24, @CGUID+9), 
(24, @CGUID+10),
(24, @CGUID+11),
(24, @CGUID+12),
(24, @CGUID+13),
(24, @CGUID+14),
(24, @CGUID+15),
(24, @CGUID+16),
(24, @CGUID+17),
(24, @CGUID+18),
(24, @CGUID+19),
(24, @CGUID+20),
(24, @CGUID+21),
(24, @CGUID+22),
(24, @CGUID+23),
(24, @CGUID+24),
(24, @CGUID+25),
(24, @CGUID+26),
(24, @CGUID+27),
(24, @CGUID+28),
(24, @CGUID+29),
(24, @CGUID+30),
(24, @CGUID+31),
(24, @CGUID+32),
(24, @CGUID+33),
(24, @CGUID+34),
(24, @CGUID+35),
(24, @CGUID+36),
(24, @CGUID+37),
(24, @CGUID+38),
(24, @CGUID+39),
(24, @CGUID+40),
(24, @CGUID+41),
(24, @CGUID+42),
(24, @CGUID+43),
(24, @CGUID+44),
(24, @CGUID+45),
(24, @CGUID+46),
(24, @CGUID+47),
(24, @CGUID+48),
(24, @CGUID+49),
(24, @CGUID+50),
(24, @CGUID+51),
(24, @CGUID+52),
(24, @CGUID+53),
(24, @CGUID+54),
(24, @CGUID+55),
(24, @CGUID+56),
(24, @CGUID+57),
(24, @CGUID+58),
(24, @CGUID+59),
(24, @CGUID+60),
(24, @CGUID+61),
(24, @CGUID+62),
(24, @CGUID+63),
(24, @CGUID+64),
(24, @CGUID+65),
(24, @CGUID+66),
(24, @CGUID+67),
(24, @CGUID+68),
(24, @CGUID+69),
(24, @CGUID+70),
(24, @CGUID+71),
(24, @CGUID+72),
(24, @CGUID+73),
(24, @CGUID+74),
(24, @CGUID+75),
(24, @CGUID+76),
(24, @CGUID+77),
(24, @CGUID+78),
(24, @CGUID+79),
(24, @CGUID+80),
(24, @CGUID+81),
(24, @CGUID+82),
(24, @CGUID+83),
(24, @CGUID+84),
(24, @CGUID+85);

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+374 AND `eventEntry`=24;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(24, @OGUID+0),  
(24, @OGUID+1),  
(24, @OGUID+2),  
(24, @OGUID+3),  
(24, @OGUID+4),  
(24, @OGUID+5),  
(24, @OGUID+6),  
(24, @OGUID+7),  
(24, @OGUID+8),  
(24, @OGUID+9),  
(24, @OGUID+10), 
(24, @OGUID+11), 
(24, @OGUID+12), 
(24, @OGUID+13), 
(24, @OGUID+14), 
(24, @OGUID+15), 
(24, @OGUID+16), 
(24, @OGUID+17), 
(24, @OGUID+18), 
(24, @OGUID+19), 
(24, @OGUID+20), 
(24, @OGUID+21), 
(24, @OGUID+22), 
(24, @OGUID+23), 
(24, @OGUID+24), 
(24, @OGUID+25), 
(24, @OGUID+26), 
(24, @OGUID+27), 
(24, @OGUID+28), 
(24, @OGUID+29), 
(24, @OGUID+30), 
(24, @OGUID+31), 
(24, @OGUID+32), 
(24, @OGUID+33), 
(24, @OGUID+34), 
(24, @OGUID+35), 
(24, @OGUID+36), 
(24, @OGUID+37), 
(24, @OGUID+38), 
(24, @OGUID+39), 
(24, @OGUID+40), 
(24, @OGUID+41), 
(24, @OGUID+42), 
(24, @OGUID+43), 
(24, @OGUID+44), 
(24, @OGUID+45), 
(24, @OGUID+46), 
(24, @OGUID+47), 
(24, @OGUID+48), 
(24, @OGUID+49), 
(24, @OGUID+50), 
(24, @OGUID+51), 
(24, @OGUID+52), 
(24, @OGUID+53), 
(24, @OGUID+54), 
(24, @OGUID+55), 
(24, @OGUID+56), 
(24, @OGUID+57), 
(24, @OGUID+58), 
(24, @OGUID+59), 
(24, @OGUID+60), 
(24, @OGUID+61), 
(24, @OGUID+62), 
(24, @OGUID+63), 
(24, @OGUID+64), 
(24, @OGUID+65), 
(24, @OGUID+66), 
(24, @OGUID+67), 
(24, @OGUID+68), 
(24, @OGUID+69), 
(24, @OGUID+70), 
(24, @OGUID+71), 
(24, @OGUID+72), 
(24, @OGUID+73), 
(24, @OGUID+74), 
(24, @OGUID+75), 
(24, @OGUID+76), 
(24, @OGUID+77), 
(24, @OGUID+78), 
(24, @OGUID+79), 
(24, @OGUID+80), 
(24, @OGUID+81), 
(24, @OGUID+82), 
(24, @OGUID+83), 
(24, @OGUID+84), 
(24, @OGUID+85), 
(24, @OGUID+86), 
(24, @OGUID+87), 
(24, @OGUID+88), 
(24, @OGUID+89), 
(24, @OGUID+90), 
(24, @OGUID+91), 
(24, @OGUID+92), 
(24, @OGUID+93), 
(24, @OGUID+94), 
(24, @OGUID+95), 
(24, @OGUID+96), 
(24, @OGUID+97), 
(24, @OGUID+98), 
(24, @OGUID+99), 
(24, @OGUID+100),
(24, @OGUID+101),
(24, @OGUID+102),
(24, @OGUID+103),
(24, @OGUID+104),
(24, @OGUID+105),
(24, @OGUID+106),
(24, @OGUID+107),
(24, @OGUID+108),
(24, @OGUID+109),
(24, @OGUID+110),
(24, @OGUID+111),
(24, @OGUID+112),
(24, @OGUID+113),
(24, @OGUID+114),
(24, @OGUID+115),
(24, @OGUID+116),
(24, @OGUID+117),
(24, @OGUID+118),
(24, @OGUID+119),
(24, @OGUID+120),
(24, @OGUID+121),
(24, @OGUID+122),
(24, @OGUID+123),
(24, @OGUID+124),
(24, @OGUID+125),
(24, @OGUID+126),
(24, @OGUID+127),
(24, @OGUID+128),
(24, @OGUID+129),
(24, @OGUID+130),
(24, @OGUID+131),
(24, @OGUID+132),
(24, @OGUID+133),
(24, @OGUID+134),
(24, @OGUID+135),
(24, @OGUID+136),
(24, @OGUID+137),
(24, @OGUID+138),
(24, @OGUID+139),
(24, @OGUID+140),
(24, @OGUID+141),
(24, @OGUID+142),
(24, @OGUID+143),
(24, @OGUID+144),
(24, @OGUID+145),
(24, @OGUID+146),
(24, @OGUID+147),
(24, @OGUID+148),
(24, @OGUID+149),
(24, @OGUID+150),
(24, @OGUID+151),
(24, @OGUID+152),
(24, @OGUID+153),
(24, @OGUID+154),
(24, @OGUID+155),
(24, @OGUID+156),
(24, @OGUID+157),
(24, @OGUID+158),
(24, @OGUID+159),
(24, @OGUID+160),
(24, @OGUID+161),
(24, @OGUID+162),
(24, @OGUID+163),
(24, @OGUID+164),
(24, @OGUID+165),
(24, @OGUID+166),
(24, @OGUID+167),
(24, @OGUID+168),
(24, @OGUID+169),
(24, @OGUID+170),
(24, @OGUID+171),
(24, @OGUID+172),
(24, @OGUID+173),
(24, @OGUID+174),
(24, @OGUID+175),
(24, @OGUID+176),
(24, @OGUID+177),
(24, @OGUID+178),
(24, @OGUID+179),
(24, @OGUID+180),
(24, @OGUID+181),
(24, @OGUID+182),
(24, @OGUID+183),
(24, @OGUID+184),
(24, @OGUID+185),
(24, @OGUID+186),
(24, @OGUID+187),
(24, @OGUID+188),
(24, @OGUID+189),
(24, @OGUID+190),
(24, @OGUID+191),
(24, @OGUID+192),
(24, @OGUID+193),
(24, @OGUID+194),
(24, @OGUID+195),
(24, @OGUID+196),
(24, @OGUID+197),
(24, @OGUID+198),
(24, @OGUID+199),
(24, @OGUID+200),
(24, @OGUID+201),
(24, @OGUID+202),
(24, @OGUID+203),
(24, @OGUID+204),
(24, @OGUID+205),
(24, @OGUID+206),
(24, @OGUID+207),
(24, @OGUID+208),
(24, @OGUID+209),
(24, @OGUID+210),
(24, @OGUID+211),
(24, @OGUID+212),
(24, @OGUID+213),
(24, @OGUID+214),
(24, @OGUID+215),
(24, @OGUID+216),
(24, @OGUID+217),
(24, @OGUID+218),
(24, @OGUID+219),
(24, @OGUID+220),
(24, @OGUID+221),
(24, @OGUID+222),
(24, @OGUID+223),
(24, @OGUID+224),
(24, @OGUID+225),
(24, @OGUID+226),
(24, @OGUID+227),
(24, @OGUID+228),
(24, @OGUID+229),
(24, @OGUID+230),
(24, @OGUID+231),
(24, @OGUID+232),
(24, @OGUID+233),
(24, @OGUID+234),
(24, @OGUID+235),
(24, @OGUID+236),
(24, @OGUID+237),
(24, @OGUID+238),
(24, @OGUID+239),
(24, @OGUID+240),
(24, @OGUID+241),
(24, @OGUID+242),
(24, @OGUID+243),
(24, @OGUID+244),
(24, @OGUID+245),
(24, @OGUID+246),
(24, @OGUID+247),
(24, @OGUID+248),
(24, @OGUID+249),
(24, @OGUID+250),
(24, @OGUID+251),
(24, @OGUID+252),
(24, @OGUID+253),
(24, @OGUID+254),
(24, @OGUID+255),
(24, @OGUID+256),
(24, @OGUID+257),
(24, @OGUID+258),
(24, @OGUID+259),
(24, @OGUID+260),
(24, @OGUID+261),
(24, @OGUID+262),
(24, @OGUID+263),
(24, @OGUID+264),
(24, @OGUID+265),
(24, @OGUID+266),
(24, @OGUID+267),
(24, @OGUID+268),
(24, @OGUID+269),
(24, @OGUID+270),
(24, @OGUID+271),
(24, @OGUID+272),
(24, @OGUID+273),
(24, @OGUID+274),
(24, @OGUID+275),
(24, @OGUID+276),
(24, @OGUID+277),
(24, @OGUID+278),
(24, @OGUID+279),
(24, @OGUID+280),
(24, @OGUID+281),
(24, @OGUID+282),
(24, @OGUID+283),
(24, @OGUID+284),
(24, @OGUID+285),
(24, @OGUID+286),
(24, @OGUID+287),
(24, @OGUID+288),
(24, @OGUID+289),
(24, @OGUID+290),
(24, @OGUID+291),
(24, @OGUID+292),
(24, @OGUID+293),
(24, @OGUID+294),
(24, @OGUID+295),
(24, @OGUID+296),
(24, @OGUID+297),
(24, @OGUID+298),
(24, @OGUID+299),
(24, @OGUID+300),
(24, @OGUID+301),
(24, @OGUID+302),
(24, @OGUID+303),
(24, @OGUID+304),
(24, @OGUID+305),
(24, @OGUID+306),
(24, @OGUID+307),
(24, @OGUID+308),
(24, @OGUID+309),
(24, @OGUID+310),
(24, @OGUID+311),
(24, @OGUID+312),
(24, @OGUID+313),
(24, @OGUID+314),
(24, @OGUID+315),
(24, @OGUID+316),
(24, @OGUID+317),
(24, @OGUID+318),
(24, @OGUID+319),
(24, @OGUID+320),
(24, @OGUID+321),
(24, @OGUID+322),
(24, @OGUID+323),
(24, @OGUID+324),
(24, @OGUID+325),
(24, @OGUID+326),
(24, @OGUID+327),
(24, @OGUID+328),
(24, @OGUID+329),
(24, @OGUID+330),
(24, @OGUID+331),
(24, @OGUID+332),
(24, @OGUID+333),
(24, @OGUID+334),
(24, @OGUID+335),
(24, @OGUID+336),
(24, @OGUID+337),
(24, @OGUID+338),
(24, @OGUID+339),
(24, @OGUID+340),
(24, @OGUID+341),
(24, @OGUID+342),
(24, @OGUID+343),
(24, @OGUID+344),
(24, @OGUID+345),
(24, @OGUID+346),
(24, @OGUID+347),
(24, @OGUID+348),
(24, @OGUID+349),
(24, @OGUID+350),
(24, @OGUID+351),
(24, @OGUID+352),
(24, @OGUID+353),
(24, @OGUID+354),
(24, @OGUID+355),
(24, @OGUID+356),
(24, @OGUID+357),
(24, @OGUID+358),
(24, @OGUID+359),
(24, @OGUID+360),
(24, @OGUID+361),
(24, @OGUID+362),
(24, @OGUID+363),
(24, @OGUID+364),
(24, @OGUID+365),
(24, @OGUID+366),
(24, @OGUID+367),
(24, @OGUID+368),
(24, @OGUID+369),
(24, @OGUID+370),
(24, @OGUID+371),
(24, @OGUID+372),
(24, @OGUID+373),
(24, @OGUID+374);

DELETE FROM `npc_vendor` WHERE `entry` IN (23522, 23525, 23710);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 23522 (Arlen Lochlan)
(23522, 33043, 1, 0, 0, 1), -- The Essential Brewfest Pretzel
(23522, 4540, 2, 0, 0, 1), -- Tough Hunk of Bread
(23522, 4541, 3, 0, 0, 1), -- Freshly Baked Bread
(23522, 4542, 4, 0, 0, 1), -- Moist Cornbread
(23522, 4544, 5, 0, 0, 1), -- Mulgore Spice Bread
(23522, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(23522, 8950, 7, 0, 0, 1), -- Homemade Cherry Pie
(23522, 27855, 8, 0, 0, 1), -- Mag'har Grainbread
(23522, 33449, 9, 0, 0, 1), -- Crusty Flatbread
(23522, 35950, 10, 0, 0, 1), -- Sweet Potato Bread
(23522, 58260, 11, 0, 0, 1), -- Pine Nut Bread
(23522, 58261, 12, 0, 0, 1), -- Buttery Wheat Roll
-- 23525 (Brother Cartwright)
(23525, 2723, 1, 0, 0, 1), -- Bottle of Dalaran Noir
(23525, 2593, 2, 0, 0, 1), -- Flask of Stormwind Tawny
(23525, 2596, 3, 0, 0, 1), -- Skin of Dwarven Stout
(23525, 2594, 4, 0, 0, 1), -- Flagon of Dwarven Mead
(23525, 2595, 5, 0, 0, 1), -- Jug of Badlands Bourbon
-- 23710 (Belbi Quikswitch)
(23710, 33968, 1, 0, 2274, 1), -- Blue Brewfest Hat
(23710, 33864, 2, 0, 2274, 1), -- Brown Brewfest Hat
(23710, 33967, 3, 0, 2274, 1), -- Green Brewfest Hat
(23710, 33969, 4, 0, 2274, 1), -- Purple Brewfest Hat
(23710, 33863, 5, 0, 2276, 1), -- Brewfest Dress
(23710, 33966, 6, 0, 2275, 1), -- Brewfest Slippers
(23710, 33862, 7, 0, 2276, 1), -- Brewfest Regalia
(23710, 33868, 8, 0, 2275, 1), -- Brewfest Boots
(23710, 37571, 9, 0, 2397, 1), -- "Brew of the Month" Club Membership Form
(23710, 33047, 11, 0, 2275, 1), -- Belbi's Eyesight Enhancing Romance Goggles
(23710, 90427, 12, 0, 2275, 1), -- Pandaren Brewpack
(23710, 71137, 13, 0, 2276, 1), -- Brewfest Keg Pony
(23710, 33927, 14, 0, 2275, 1), -- Brewfest Pony Keg
(23710, 46707, 15, 0, 2275, 1), -- Pint-Sized Pink Pachyderm
(23710, 32233, 16, 0, 2276, 1), -- Wolpertinger's Tankard
(23710, 37750, 17, 0, 2398, 1), -- Fresh Brewfest Hops
(23710, 37816, 18, 0, 2399, 1); -- Preserved Brewfest Hops

DELETE FROM `creature_template_addon` WHERE `entry` IN (23510, 23482, 24364, 24468, 23558, 23521, 23710, 23627, 23683, 23522, 23628, 23684, 23486, 24710, 23525, 27215, 23481, 40441);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(23510, 0, 0x0, 0x1, ''), -- Thunderbrew Apprentice
(23482, 0, 0x0, 0x1, ''), -- Barleybrew Apprentice
(24364, 0, 0x0, 0x101, '44067'), -- Flynn Firebrew - Supplier Mark
(24468, 0, 0x0, 0x1, '44068'), -- Pol Amberstill - Base Camp Mark
(23558, 0, 0x0, 0x1, ''), -- Neill Ramstein
(23521, 0, 0x0, 0x1, ''), -- Anne Summers
(23710, 0, 0x0, 0x1, ''), -- Belbi Quikswitch
(23627, 0, 0x0, 0x101, ''), -- Becan Barleybrew
(23683, 0, 0x0, 0x101, ''), -- Maeve Barleybrew
(23522, 0, 0x0, 0x1, ''), -- Arlen Lochlan
(23628, 0, 0x0, 0x101, ''), -- Daran Thunderbrew
(23684, 0, 0x0, 0x101, ''), -- Ita Thunderbrew
(23486, 0, 0x0, 0x1, ''), -- Goldark Snipehunter
(24710, 0, 0x0, 0x1, ''), -- Ipfelkofer Ironkeg
(23525, 0, 0x0, 0x1, ''), -- Brother Cartwright
(27215, 0, 0x0, 0x1, ''), -- Boxey Boltspinner
(23481, 0, 0x0, 0x1, ''), -- Keiran Donoghue
(40441, 0, 0x0, 0x1, ''); -- Battered Brewmaster
