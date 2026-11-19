SET @CGUID := 361880;
SET @OGUID := 225989;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+76;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 23808, 1, 1, 1, 0, 1171.494, -4118.168, 20.4874, 1.074811, 120, 5, 1), -- [DND] Brewfest Keg Move to Target (Area: Durotar) (possible waypoints or random movement)
(@CGUID+1, 24484, 1, 1, 1, 0, 1163.045, -4144.958, 21.52604, 2.687807, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43907 - Brewfest Reveler - Blood Elf)
(@CGUID+2, 24657, 1, 1, 1, 0, 1155.069, -4142.635, 21.30903, 0.2617994, 120, 0, 0), -- Glodrak Huntsniper (Area: Durotar)
(@CGUID+3, 24498, 1, 1, 1, 0, 1167.21, -4107.191, 19.29861, 6.056293, 120, 0, 0), -- Cort Gorestein (Area: Durotar)
(@CGUID+4, 24711, 1, 1, 1, 0, 1158.045, -4160.927, 21.24508, 0.2047817, 120, 0, 0), -- Tapper Swindlekeg (Area: Durotar) (Auras: 50552 - Horde Questgiver Tries Dire Brew, 50551 - Horde Questgiver Takes a drink)
(@CGUID+5, 23606, 1, 1, 1, 0, 1177.618, -4164.182, 22.01465, 1.89964, 120, 0, 0), -- Suntouched Apprentice (Area: Durotar)
(@CGUID+6, 24372, 1, 1, 1, 0, 1168.285, -4116.309, 20.43056, 5.707227, 120, 0, 0), -- Drohn's Distillery Festive Keg (Area: Durotar)
(@CGUID+7, 23603, 1, 1, 1, 0, 1161.67, -4133.085, 21.42014, 5.689773, 120, 0, 0), -- Uta Roughdough (Area: Durotar)
(@CGUID+8, 24484, 1, 1, 1, 0, 1181.422, -4157.077, 21.68576, 4.625123, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43915 - Brewfest Reveler - Tauren)
(@CGUID+9, 24484, 1, 1, 1, 0, 1165.66, -4152.851, 21.72917, 4.660029, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43914 - Brewfest Reveler - Orc)
(@CGUID+10, 24484, 1, 1, 1, 0, 1174.622, -4130.429, 21.34797, 0.9599311, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43916 - Brewfest Reveler - Troll)
(@CGUID+11, 24484, 1, 1, 1, 0, 1170.179, -4147.186, 21.67576, 5.61996, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43917 - Brewfest Reveler - Undead)
(@CGUID+12, 24484, 1, 1, 1, 0, 1179.835, -4127.41, 21.29514, 2.617994, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43917 - Brewfest Reveler - Undead)
(@CGUID+13, 24484, 1, 1, 1, 0, 1184.415, -4153.962, 21.60938, 1.361357, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43914 - Brewfest Reveler - Orc)
(@CGUID+14, 24501, 1, 1, 1, 0, 1168.625, -4103.194, 18.79514, 5.916666, 120, 0, 0), -- Drohn's Distillery Apprentice (Area: Durotar)
(@CGUID+15, 24492, 1, 1, 1, 0, 1173.965, -4102.738, 18.85311, 5.811946, 120, 0, 0), -- Drohn's Distillery Barker (Area: Durotar) (Auras: )
(@CGUID+16, 24766, 1, 1, 1, 0, 1191.486, -4135.007, 22.05243, 6.161012, 120, 0, 0), -- [DND] Brewfest Face Me Bunny (Area: Durotar)
(@CGUID+17, 24484, 1, 1, 1, 0, 1190.465, -4137.359, 21.92014, 3.01942, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43915 - Brewfest Reveler - Tauren)
(@CGUID+18, 24484, 1, 1, 1, 0, 1193.163, -4140.776, 21.90567, 4.956735, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43915 - Brewfest Reveler - Tauren)
(@CGUID+19, 24484, 1, 1, 1, 0, 1178.734, -4115.299, 20.46701, 0.6981317, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43916 - Brewfest Reveler - Troll)
(@CGUID+20, 24484, 1, 1, 1, 0, 1183.611, -4120.368, 21.1775, 0.03490658, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43915 - Brewfest Reveler - Tauren)
(@CGUID+21, 24109, 1, 1, 1, 0, 1193.832, -4176.846, 22.79314, 1.064651, 120, 0, 0), -- [DND] Brewfest Target Dummy Move To Target (Area: Durotar)
(@CGUID+22, 24108, 1, 1, 1, 0, 1194.807, -4175.846, 22.68178, 3.939258, 120, 0, 0), -- Self-Turning and Oscillating Utility Target (Area: Durotar)
(@CGUID+23, 23703, 1, 1, 1, 0, 1191.578, -4114.137, 21.47791, 2.234021, 120, 0, 0), -- [DND] Brewfest Dark Iron Event Generator (Area: Durotar)
(@CGUID+24, 23605, 1, 1, 1, 0, 1199.837, -4142.656, 22.13296, 2.374498, 120, 0, 0), -- Bron (Area: Durotar)
(@CGUID+25, 24484, 1, 1, 1, 0, 1184.75, -4106.096, 19.78307, 2.635447, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43915 - Brewfest Reveler - Tauren)
(@CGUID+26, 24484, 1, 1, 1, 0, 1180.238, -4103.596, 19.22917, 5.707227, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43916 - Brewfest Reveler - Troll)
(@CGUID+27, 23604, 1, 1, 1, 0, 1185.87, -4089.88, 18.52143, 4.712389, 120, 0, 0), -- Agnes Farwithers (Area: Durotar)
(@CGUID+28, 24109, 1, 1, 1, 0, 1203.898, -4166.512, 23.09603, 4.433136, 120, 0, 0), -- [DND] Brewfest Target Dummy Move To Target (Area: Durotar)
(@CGUID+29, 23706, 1, 1, 1, 0, 1207.493, -4132.774, 23.19097, 4.764749, 120, 0, 0), -- Gordok Festive Keg (Area: Durotar)
(@CGUID+30, 23488, 1, 1, 1, 0, 1204.748, -4118.993, 23.00868, 5.986479, 120, 0, 0), -- Brewfest Crowd (Area: Durotar)
(@CGUID+31, 24484, 1, 1, 1, 0, 1203.616, -4185.603, 24.2934, 0.9552017, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+32, 23511, 1, 1, 1, 0, 1213.04, -4126.611, 23.69618, 2.426008, 120, 0, 0), -- Gordok Brew Apprentice (Area: Durotar)
(@CGUID+33, 23703, 1, 1, 1, 0, 1195.446, -4111.564, 21.43056, 5.602507, 120, 0, 0), -- [DND] Brewfest Dark Iron Event Generator (Area: Durotar)
(@CGUID+34, 24495, 1, 1, 1, 0, 1177.757, -4094.491, 18.27431, 5.393067, 120, 0, 0), -- Blix Fixwidget (Area: Durotar)
(@CGUID+35, 24484, 1, 1, 1, 0, 1200.29, -4182.222, 23.64837, 6.205039, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+36, 23808, 1, 1, 1, 0, 1204.801, -4130.746, 23.04626, 4.114602, 120, 5, 1), -- [DND] Brewfest Keg Move to Target (Area: Durotar) (possible waypoints or random movement)
(@CGUID+37, 24484, 1, 1, 1, 0, 1203.726, -4182.491, 24.11111, 4.67725, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+38, 24497, 1, 1, 1, 0, 1179.486, -4216.002, 23.89583, 0.9948376, 120, 0, 0), -- Ram Master Ray (Area: Durotar) (Auras: 44069 - See Supplier Mark, 43492 - Brewfest - apple trap - Unfriendly DND)
(@CGUID+39, 24484, 1, 1, 1, 0, 1202.313, -4124.241, 23.13715, 4.014257, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43914 - Brewfest Reveler - Orc)
(@CGUID+40, 24484, 1, 1, 1, 0, 1201.882, -4110.797, 21.8941, 1.815142, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43916 - Brewfest Reveler - Troll)
(@CGUID+41, 24484, 1, 1, 1, 0, 1205.642, -4114.721, 22.66146, 6.161012, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43907 - Brewfest Reveler - Blood Elf)
(@CGUID+42, 24484, 1, 1, 1, 0, 1196.538, -4098.118, 19.96629, 0.2094395, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43907 - Brewfest Reveler - Blood Elf)
(@CGUID+43, 24484, 1, 1, 1, 0, 1201.608, -4128.668, 23.02083, 0.7853982, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43917 - Brewfest Reveler - Undead)
(@CGUID+44, 23808, 1, 1, 1, 0, 1199.97, -4089.867, 19.89582, 0.707508, 120, 0, 0), -- [DND] Brewfest Keg Move to Target (Area: Durotar)
(@CGUID+45, 24493, 1, 1, 1, 0, 1209.473, -4095.635, 21.57173, 3.979351, 120, 0, 0), -- T'chali's Voodoo Brewery Barker (Area: Durotar) (Auras: )
(@CGUID+46, 24463, 1, 1, 1, 0, 1175.401, -4231.024, 23.13774, 1.225081, 120, 0, 0), -- Swift Racing Ram (Area: Durotar)
(@CGUID+47, 24510, 1, 1, 1, 0, 1183.783, -4219.568, 24.22222, 1.082104, 120, 0, 0), -- Driz Tumblequick (Area: Durotar) (Auras: 44068 - Base Camp Mark)
(@CGUID+48, 24462, 1, 1, 1, 0, 1167.696, -4228.95, 22.19206, 0.840323, 120, 0, 0), -- Racing Ram (Area: Durotar)
(@CGUID+49, 23685, 1, 1, 1, 0, 1212.449, -4119.561, 23.76855, 2.932153, 120, 0, 0), -- Gordok Brew Barker (Area: Durotar) (Auras: )
(@CGUID+50, 24484, 1, 1, 1, 0, 1207.182, -4107.929, 22.34896, 5.637414, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43915 - Brewfest Reveler - Tauren)
(@CGUID+51, 24484, 1, 1, 1, 0, 1201.976, -4096.797, 20.55908, 3.508112, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43914 - Brewfest Reveler - Orc)
(@CGUID+52, 23696, 1, 1, 1, 0, 1214.764, -4123.045, 23.9566, 2.478368, 120, 0, 0), -- Gordok Brew Chief (Area: Durotar)
(@CGUID+53, 23533, 1, 1, 1, 0, 1209.215, -4090.931, 21.28327, 3.944444, 120, 0, 0), -- T'chali's Voodoo Brewery Apprentice (Area: Durotar)
(@CGUID+54, 23488, 1, 1, 1, 0, 1229.113, -4139.306, 25.47239, 2.234021, 120, 0, 0), -- Brewfest Crowd (Area: Durotar)
(@CGUID+55, 24499, 1, 1, 1, 0, 1206.252, -4088.099, 20.83624, 4.258604, 120, 0, 0), -- Ja'ron (Area: Durotar)
(@CGUID+56, 27707, 1, 1, 1, 0, 1169.965, -4236.304, 22.52709, 0.8984495, 120, 0, 0), -- Great Brewfest Kodo (Area: Durotar)
(@CGUID+57, 24766, 1, 1, 1, 0, 1207.184, -4227.684, 22.99848, 3.246312, 120, 0, 0), -- [DND] Brewfest Face Me Bunny (Area: Durotar)
(@CGUID+58, 24484, 1, 1, 1, 0, 1238.547, -4136.215, 41.65269, 1.651419, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+59, 24484, 1, 1, 1, 0, 1237.851, -4127.599, 42.59955, 4.793012, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+60, 23488, 1, 1, 1, 0, 1229.458, -4090.024, 23.11458, 3.124139, 120, 0, 0), -- Brewfest Crowd (Area: Durotar)
(@CGUID+61, 24527, 1, 1, 1, 0, 1332.962, -4638.893, 24.27373, 0.9948376, 120, 0, 0), -- Bok Dropcertain (Area: Durotar) (Auras: 44067 - Supplier Mark)
(@CGUID+62, 24484, 1, 1, 1, 0, 1366.889, -4343.872, 28.69971, 2.066002, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+63, 24484, 1, 1, 1, 0, 1365.394, -4341.104, 28.69971, 5.207595, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+64, 24484, 1, 1, 1, 0, 1363.67, -4344.874, 28.69971, 0.8028514, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+65, 24484, 1, 1, 1, 0, 1362.757, -4341.63, 28.69971, 0.1970039, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+66, 24484, 1, 1, 1, 0, 1358.51, -4338.264, 27.35806, 5.391015, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+67, 24484, 1, 1, 1, 0, 1360.122, -4340.262, 27.82292, 2.249422, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+68, 24484, 1, 1, 1, 0, 1361.25, -4337.616, 28.27951, 4.30928, 120, 0, 0), -- Brewfest Reveler (Area: Durotar) (Auras: 43911 - Brewfest Reveler - Goblin)
(@CGUID+69, 19175, 1, 1, 1, 0, 1614.998, -4402.952, 15.43872, 0.1570796, 120, 0, 0), -- Orc Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+70, 19175, 1, 1, 1, 0, 1616.771, -4402.656, 15.60533, 3.333579, 120, 0, 0), -- Orc Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+71, 19177, 1, 1, 1, 0, 1773.523, -4360.087, 102.4606, 1.291544, 120, 0, 0), -- Troll Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+72, 19177, 1, 1, 1, 0, 1774.47, -4356.316, 102.4248, 4.485496, 120, 0, 0), -- Troll Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+73, 19177, 1, 1, 1, 0, 1580.592, -4192.995, 53.6728, 4.363323, 120, 0, 0), -- Troll Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+74, 19176, 1, 1, 1, 0, 1579.438, -4195.903, 53.73126, 1.151917, 120, 0, 0), -- Tauren Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+75, 19177, 1, 1, 1, 0, 1722.67, -4068.328, 49.18607, 0.715585, 120, 0, 0), -- Troll Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+76, 19177, 1, 1, 1, 0, 1724.26, -4067.033, 49.31904, 3.769911, 120, 0, 0); -- Troll Commoner (Area: Orgrimmar) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget; 33208 - Gossip NPC Periodic - Talk)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+297;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,  186189, 1, 1, 1, 0, 1162.292, -4125.667, 22.05271, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+1,  186189, 1, 1, 1, 0, 1186.351, -4162.457, 22.59569, 6.248279, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+2,  186189, 1, 1, 1, 0, 1162.663, -4124.483, 21.9933, 4.590216, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+3,  180037, 1, 1, 1, 0, 1163.54, -4112.903, 20.00529, 3.700105, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+4,  186189, 1, 1, 1, 0, 1162.969, -4125.795, 22.054, 1.239183, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+5,  186189, 1, 1, 1, 0, 1186.582, -4161.349, 22.5721, 4.101525, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+6,  180037, 1, 1, 1, 0, 1160.96, -4116.95, 20.53586, 1.448622, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+7,  180037, 1, 1, 1, 0, 1154.96, -4144.643, 21.2066, 2.809975, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+8,  180037, 1, 1, 1, 0, 1153.578, -4141.007, 21.19898, 4.380776, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+9,  186229, 1, 1, 1, 0, 1154.432, -4156.542, 20.29162, 3.857183, 0, 0, 0, 1, 120, 255, 1), -- BREWFEST (Area: Durotar)
(@OGUID+10, 180698, 1, 1, 1, 0, 1162.526, -4125.135, 20.95932, 1.169369, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+11, 186186, 1, 1, 1, 0, 1167.47, -4116.202, 20.06157, 6.178466, 0, 0, 0, 1, 120, 255, 1), -- Drohn's Distillery Festive Keg (Area: Durotar)
(@OGUID+12, 180698, 1, 1, 1, 0, 1163.661, -4122.28, 20.8516, 4.32842, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+13, 186681, 1, 1, 1, 0, 1178.698, -4170.585, 21.72588, 1.710422, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Durotar)
(@OGUID+14, 186681, 1, 1, 1, 0, 1157.767, -4130.953, 21.27318, 5.724681, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Durotar)
(@OGUID+15, 186189, 1, 1, 1, 0, 1164.158, -4122.186, 21.9197, 2.949595, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+16, 186252, 1, 1, 1, 0, 1152.024, -4142.814, 21.5398, 4.590216, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+17, 186252, 1, 1, 1, 0, 1158.477, -4116.34, 20.51812, 4.520406, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+18, 180749, 1, 1, 1, 0, 1175.273, -4168.577, 22.16676, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Durotar)
(@OGUID+19, 186189, 1, 1, 1, 0, 1162.977, -4122.835, 21.99089, 3.246347, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+20, 186189, 1, 1, 1, 0, 1163.425, -4121.463, 21.9197, 3.054327, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+21, 186189, 1, 1, 1, 0, 1164.083, -4123, 21.95483, 0.4712385, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+22, 186189, 1, 1, 1, 0, 1161.986, -4125.177, 22.03619, 1.431168, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+23, 180353, 1, 1, 1, 0, 1187.729, -4154.596, 21.49498, 2.408554, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+24, 180353, 1, 1, 1, 0, 1161.373, -4134.856, 21.35069, 4.834563, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+25, 180353, 1, 1, 1, 0, 1181.399, -4161.04, 21.54865, 4.834563, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+26, 180353, 1, 1, 1, 0, 1171.319, -4162.441, 21.97743, 5.567601, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+27, 186189, 1, 1, 1, 0, 1189.7, -4159.596, 22.55126, 1.483528, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+28, 186189, 1, 1, 1, 0, 1190.002, -4154.787, 22.65598, 3.700105, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+29, 186682, 1, 1, 1, 0, 1166.573, -4104.804, 18.88715, 5.969027, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Beer Tent (Area: Durotar)
(@OGUID+30, 180698, 1, 1, 1, 0, 1189.946, -4154.203, 21.56183, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+31, 180698, 1, 1, 1, 0, 1186.689, -4162.113, 21.48204, 2.303831, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+32, 180698, 1, 1, 1, 0, 1189.318, -4159.596, 21.41427, 3.944446, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+33, 186189, 1, 1, 1, 0, 1189.063, -4158.853, 22.5478, 4.81711, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+34, 186189, 1, 1, 1, 0, 1189.406, -4160.272, 22.53218, 1.745327, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+35, 180037, 1, 1, 1, 0, 1165.962, -4097.646, 18.31001, 6.161013, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+36, 180353, 1, 1, 1, 0, 1196.776, -4145.948, 21.79974, 1.692969, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+37, 186717, 1, 1, 1, 0, 1173.078, -4101.189, 18.58095, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+38, 186680, 1, 1, 1, 0, 1188.122, -4161.418, 21.58427, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Canopy (Area: Durotar)
(@OGUID+39, 186189, 1, 1, 1, 0, 1190.533, -4153.818, 22.67434, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+40, 186189, 1, 1, 1, 0, 1187.623, -4162.168, 22.59038, 3.909541, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+41, 186189, 1, 1, 1, 0, 1189.002, -4154.228, 22.62299, 1.850049, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+42, 186252, 1, 1, 1, 0, 1189.415, -4173.481, 22.8514, 5.129194, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+43, 180037, 1, 1, 1, 0, 1189.203, -4165.234, 21.74556, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+44, 180749, 1, 1, 1, 0, 1169.28, -4107.168, 19.22845, 2.094393, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Durotar)
(@OGUID+45, 186189, 1, 1, 1, 0, 1187.354, -4161.575, 22.57396, 0.5410506, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+46, 186189, 1, 1, 1, 0, 1189.571, -4153.46, 22.64215, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+47, 186189, 1, 1, 1, 0, 1188.727, -4160.186, 22.51655, 3.665196, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+48, 186189, 1, 1, 1, 0, 1172.257, -4098.749, 19.1679, 4.398232, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+49, 186189, 1, 1, 1, 0, 1171.568, -4098.882, 19.14358, 0.8726639, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+50, 179970, 1, 1, 1, 0, 1174.014, -4092.774, 17.89063, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Durotar)
(@OGUID+51, 180698, 1, 1, 1, 0, 1172.047, -4098.309, 18.02673, 5.881761, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+52, 180037, 1, 1, 1, 0, 1167.04, -4095.097, 17.76287, 1.029743, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+53, 186252, 1, 1, 1, 0, 1200.83, -4162.42, 22.95492, 6.063959, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+54, 186681, 1, 1, 1, 0, 1203.672, -4146.528, 22.13542, 2.316317, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Durotar)
(@OGUID+55, 186252, 1, 1, 1, 0, 1167.542, -4091.236, 18.26023, 4.24115, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+56, 186189, 1, 1, 1, 0, 1171.859, -4098.158, 19.09846, 3.630291, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+57, 186189, 1, 1, 1, 0, 1172.63, -4097.924, 19.12103, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+58, 180037, 1, 1, 1, 0, 1199.089, -4176.109, 23.20567, 0.383971, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+59, 186252, 1, 1, 1, 0, 1198.856, -4179.519, 23.40603, 0.1858179, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+60, 186185, 1, 1, 1, 0, 1208.278, -4133.236, 22.83094, 2.565632, 0, 0, 0, 1, 120, 255, 1), -- Gordok Festive Keg (Area: Durotar)
(@OGUID+61, 180749, 1, 1, 1, 0, 1211.278, -4179.668, 23.89529, 0.9599299, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Durotar)
(@OGUID+62, 180749, 1, 1, 1, 0, 1211.837, -4125.374, 23.55903, 3.036838, 0, 0, 0, 1, 120, 255, 1), -- Cheer Speaker (Area: Durotar)
(@OGUID+63, 180037, 1, 1, 1, 0, 1203.816, -4171.488, 23.38345, 4.153885, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+64, 180037, 1, 1, 1, 0, 1213.488, -4132.486, 23.13009, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+65, 180353, 1, 1, 1, 0, 1176.448, -4218.412, 23.35283, 3.595379, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+66, 179970, 1, 1, 1, 0, 1174.59, -4091.538, 17.84028, 2.617989, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Durotar)
(@OGUID+67, 179970, 1, 1, 1, 0, 1175.764, -4090.859, 17.87783, 3.892087, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Durotar)
(@OGUID+68, 186252, 1, 1, 1, 0, 1207.118, -4170.915, 24.33955, 4.607672, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+69, 180353, 1, 1, 1, 0, 1212.345, -4138.17, 22.97396, 3.490667, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+70, 186252, 1, 1, 1, 0, 1214.934, -4151.243, 23.73713, 5.737927, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+71, 179970, 1, 1, 1, 0, 1177.653, -4092.012, 18.02951, 4.834563, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Durotar)
(@OGUID+72, 179970, 1, 1, 1, 0, 1176.859, -4092.951, 18.04568, 3.961899, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Durotar)
(@OGUID+73, 179970, 1, 1, 1, 0, 1175.833, -4093.286, 18.01563, 2.199115, 0, 0, 0, 1, 120, 255, 1), -- Replace Crate 02 (Area: Durotar)
(@OGUID+74, 186252, 1, 1, 1, 0, 1175.552, -4080.288, 18.35061, 0.6632232, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+75, 186681, 1, 1, 1, 0, 1184.915, -4085.128, 18.21797, 4.852017, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Food Tent (Area: Durotar)
(@OGUID+76, 186717, 1, 1, 1, 0, 1172.896, -4217.665, 22.8744, 1.780234, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+77, 180037, 1, 1, 1, 0, 1212.172, -4135.202, 23.14898, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+78, 179973, 1, 1, 1, 0, 1175.498, -4086.158, 17.7428, 2.82743, 0, 0, 0, 1, 120, 255, 1), -- Inn Barrel (Area: Durotar)
(@OGUID+79, 179973, 1, 1, 1, 0, 1176.016, -4088.189, 17.80035, 0.1047193, 0, 0, 0, 1, 120, 255, 1), -- Inn Barrel (Area: Durotar)
(@OGUID+80, 179973, 1, 1, 1, 0, 1177.417, -4086.594, 17.84794, 5.532695, 0, 0, 0, 1, 120, 255, 1), -- Inn Barrel (Area: Durotar)
(@OGUID+81, 180353, 1, 1, 1, 0, 1213.84, -4152.807, 22.76103, 0.6108634, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+82, 180353, 1, 1, 1, 0, 1183.905, -4091.085, 18.35069, 1.047198, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+83, 186252, 1, 1, 1, 0, 1166.53, -4225.109, 22.90209, 3.630291, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+84, 180037, 1, 1, 1, 0, 1196.549, -4082.128, 19.38479, 3.211419, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+85, 180698, 1, 1, 1, 0, 1215.613, -4116.853, 23.81499, 2.844883, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+86, 186189, 1, 1, 1, 0, 1215.026, -4116.637, 24.92337, 4.607672, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+87, 180037, 1, 1, 1, 0, 1220.146, -4119.405, 24.58892, 2.44346, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+88, 180037, 1, 1, 1, 0, 1221.424, -4117.778, 24.72447, 5.916668, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+89, 180353, 1, 1, 1, 0, 1222.938, -4175.712, 24.06632, 4.049168, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+90, 180353, 1, 1, 1, 0, 1214.113, -4117.646, 23.79053, 2.740162, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+91, 186252, 1, 1, 1, 0, 1221.521, -4141.783, 24.62254, 5.715981, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+92, 186252, 1, 1, 1, 0, 1220.684, -4131.749, 24.89619, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+93, 180698, 1, 1, 1, 0, 1192.101, -4083.911, 18.80872, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+94, 186252, 1, 1, 1, 0, 1188.957, -4076.316, 19.38857, 6.19592, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+95, 180037, 1, 1, 1, 0, 1201.901, -4088.207, 20.35022, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+96, 180353, 1, 1, 1, 0, 1182.712, -4221.946, 24.04861, 3.892087, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+97, 186717, 1, 1, 1, 0, 1217.877, -4116.762, 24.26042, 2.984498, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+98, 186682, 1, 1, 1, 0, 1215.611, -4125.455, 23.46921, 2.705255, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Beer Tent (Area: Durotar)
(@OGUID+99, 186252, 1, 1, 1, 0, 1163.165, -4236.194, 22.55503, 5.026549, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+100, 186189, 1, 1, 1, 0, 1191.908, -4084.554, 19.8605, 0.7504908, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+101, 186189, 1, 1, 1, 0, 1215.568, -4117.179, 24.91469, 5.567601, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+102, 186189, 1, 1, 1, 0, 1216.585, -4116.908, 24.92835, 0.2792516, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+103, 186187, 1, 1, 1, 0, 1198.163, -4086.488, 19.23897, 4.398232, 0, 0, 0, 1, 120, 255, 1), -- T'chali's Voodoo Brew Festive Keg (Area: Durotar)
(@OGUID+104, 186709, 1, 1, 1, 0, 1186.977, -4226.472, 25.21957, 0.9773831, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Durotar)
(@OGUID+105, 186709, 1, 1, 1, 0, 1183.873, -4224.344, 24.94407, 0.8901166, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Durotar)
(@OGUID+106, 186709, 1, 1, 1, 0, 1185.399, -4225.5, 25.07382, 0.9250238, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Durotar)
(@OGUID+107, 186680, 1, 1, 1, 0, 1177.599, -4223.518, 22.93285, 1.029743, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Canopy (Area: Durotar)
(@OGUID+108, 186189, 1, 1, 1, 0, 1216.082, -4116.26, 24.90165, 2.234018, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+109, 186717, 1, 1, 1, 0, 1218.252, -4108.524, 23.54216, 3.246347, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+110, 180353, 1, 1, 1, 0, 1222.688, -4141.073, 24.19731, 2.617989, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+111, 180353, 1, 1, 1, 0, 1227.38, -4159.139, 24.25072, 0.05235888, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+112, 186189, 1, 1, 1, 0, 1192.627, -4084.627, 19.93342, 3.68265, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+113, 186189, 1, 1, 1, 0, 1192.583, -4084.061, 19.91093, 0.2792516, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+114, 186189, 1, 1, 1, 0, 1192.304, -4083.42, 19.8657, 2.967041, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+115, 180353, 1, 1, 1, 0, 1217.165, -4109.021, 23.70313, 5.585054, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+116, 180353, 1, 1, 1, 0, 1210.517, -4094.943, 21.57292, 3.246347, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+117, 186252, 1, 1, 1, 0, 1181.547, -4233.99, 24.68378, 1.53589, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+118, 186189, 1, 1, 1, 0, 1216.505, -4095.924, 23.13636, 5.759588, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+119, 186717, 1, 1, 1, 0, 1336.016, -4365.609, 26.711, 5.462882, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+120, 186717, 1, 1, 1, 0, 1216.644, -4100.559, 22.75926, 3.665196, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+121, 179975, 1, 1, 1, 0, 1167.644, -4241.037, 22.44431, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- Water Trough Small (Area: Durotar)
(@OGUID+122, 180698, 1, 1, 1, 0, 1215.884, -4095.212, 22.01696, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+123, 186189, 1, 1, 1, 0, 1215.254, -4095.698, 23.12354, 3.508117, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+124, 186189, 1, 1, 1, 0, 1216.931, -4094.993, 23.10163, 3.403396, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+125, 186189, 1, 1, 1, 0, 1215.323, -4095.014, 23.11111, 4.084071, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+126, 186252, 1, 1, 1, 0, 1227.724, -4157.139, 24.8812, 6.03884, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+127, 186252, 1, 1, 1, 0, 1225.983, -4093.2, 23.64176, 2.268925, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+128, 186252, 1, 1, 1, 0, 1215.477, -4083.882, 22.75924, 5.619962, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+129, 186252, 1, 1, 1, 0, 1229.899, -4105.236, 24.95628, 4.537859, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+130, 186252, 1, 1, 1, 0, 1202.818, -4077.88, 20.95584, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+131, 186252, 1, 1, 1, 0, 1226.885, -4119.118, 25.34722, 1.221729, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+132, 186717, 1, 1, 1, 0, 1227.339, -4433.462, 24.40195, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+133, 186714, 1, 1, 1, 0, 1222.384, -4103.804, 22.66798, 2.530723, 0, 0, 0, 1, 120, 255, 1), -- Shoutbox (Area: Durotar)
(@OGUID+134, 186717, 1, 1, 1, 0, 1100.76, -4429.736, 20.56441, 2.216565, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+135, 186717, 1, 1, 1, 0, 1362.391, -4353.755, 26.78416, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+136, 186717, 1, 1, 1, 0, 1305.785, -4408.33, 25.85153, 4.97419, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+137, 186680, 1, 1, 1, 0, 1367.2, -4341.962, 28.61637, 3.368496, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Canopy (Area: Durotar)
(@OGUID+138, 186717, 1, 1, 1, 0, 1161.778, -4398.226, 25.27202, 4.572764, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+139, 186717, 1, 1, 1, 0, 1187.47, -4228.497, 24.54514, 0.03490625, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+140, 186717, 1, 1, 1, 0, 1213.752, -4094.228, 21.89984, 3.909541, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+141, 186717, 1, 1, 1, 0, 1165.446, -4244.052, 22.40336, 0.8901166, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+142, 186682, 1, 1, 1, 0, 1208.793, -4088.248, 20.92865, 4.153885, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Beer Tent (Area: Durotar)
(@OGUID+143, 186252, 1, 1, 1, 0, 1235.432, -4147.135, 26.34798, 6.161013, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+144, 186252, 1, 1, 1, 0, 1173.67, -4242.922, 24.01151, 3.298687, 0, 0, 0, 1, 120, 255, 1), -- Fence (Area: Durotar)
(@OGUID+145, 180037, 1, 1, 1, 0, 1174.106, -4239.396, 23.05208, 3.298687, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+146, 180353, 1, 1, 1, 0, 1215.382, -4101.462, 22.77083, 3.228859, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+147, 186173, 1, 1, 1, 0, 1219.582, -4104.963, 24.99313, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Keg Breakable (Area: Durotar)
(@OGUID+148, 186717, 1, 1, 1, 0, 1308.472, -4448.674, 26.03033, 5.009095, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+149, 180037, 1, 1, 1, 0, 1245.139, -4147.146, 26.95318, 3.194002, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+150, 180006, 1, 1, 1, 0, 1246.729, -4156.728, 26.54697, 2.740162, 0, 0, 0, 1, 120, 255, 1), -- Outhouse (Area: Durotar)
(@OGUID+151, 180037, 1, 1, 1, 0, 1244.34, -4166.113, 26.59611, 0.3490652, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+152, 180037, 1, 1, 1, 0, 1237.472, -4161.811, 25.76779, 5.707228, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+153, 180006, 1, 1, 1, 0, 1243.181, -4162.17, 26.23796, 2.530723, 0, 0, 0, 1, 120, 255, 1), -- Outhouse (Area: Durotar)
(@OGUID+154, 180353, 1, 1, 1, 0, 1235.771, -4143.17, 26.2977, 3.455756, 0, 0, 0, 1, 120, 255, 1), -- Freestanding Torch 01 (Area: Durotar)
(@OGUID+155, 180006, 1, 1, 1, 0, 1248.582, -4151.222, 26.71534, 3.071766, 0, 0, 0, 1, 120, 255, 1), -- Outhouse (Area: Durotar)
(@OGUID+156, 180037, 1, 1, 1, 0, 1252.063, -4148.179, 26.90179, 1.902409, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+157, 180037, 1, 1, 1, 0, 1248.557, -4161.566, 26.93834, 4.049168, 0, 0, 0, 1, 120, 255, 1), -- Haybail 01 (Area: Durotar)
(@OGUID+158, 186717, 1, 1, 1, 0, 1318.333, -4549.207, 22.76087, 4.747296, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+159, 186717, 1, 1, 1, 0, 1314.639, -4599.167, 23.74962, 5.166176, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+160, 186717, 1, 1, 1, 0, 1329.559, -4637.971, 23.95576, 0.9948372, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+161, 186717, 1, 1, 1, 0, 1336.05, -4640.563, 24.45139, 1.221729, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Durotar)
(@OGUID+162, 195260, 1, 1, 1, 0, 1286.17, -4333.47, 35.695, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Durotar)
(@OGUID+163, 195265, 1, 1, 1, 0, 1312.39, -4325.31, 32.4768, 5.288348, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Durotar)
(@OGUID+164, 195265, 1, 1, 1, 0, 1311.35, -4324.43, 32.7334, 5.288348, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Durotar)
(@OGUID+165, 195264, 1, 1, 1, 0, 1309.82, -4324.27, 33.9393, 5.637414, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Medium - Brewfest (Area: Durotar)
(@OGUID+166, 195266, 1, 1, 1, 0, 1297.54, -4337.66, 38.1259, 0.1396245, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Durotar)
(@OGUID+167, 195256, 1, 1, 1, 0, 1304.6, -4345.02, 32.9993, 0.6283169, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Durotar)
(@OGUID+168, 195260, 1, 1, 1, 0, 1289.8, -4344.31, 35.5078, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Durotar)
(@OGUID+169, 195256, 1, 1, 1, 0, 1301.57, -4330.3, 33.0354, 5.794494, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Durotar)
(@OGUID+170, 186709, 1, 1, 1, 0, 1329.049, -4646.385, 24.1446, 5.881761, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Durotar)
(@OGUID+171, 186709, 1, 1, 1, 0, 1328.127, -4638.568, 24.43429, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Durotar)
(@OGUID+172, 186709, 1, 1, 1, 0, 1334.622, -4648.49, 24.75111, 0.5759573, 0, 0, 0, 1, 120, 255, 1), -- Standing Brewfest Keg (Area: Durotar)
(@OGUID+173, 186189, 1, 1, 1, 0, 1367.382, -4342.616, 29.55398, 2.007128, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+174, 180698, 1, 1, 1, 0, 1367.361, -4341.856, 28.45964, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- Party Table (Area: Durotar)
(@OGUID+175, 186189, 1, 1, 1, 0, 1368.092, -4342.213, 29.45188, 1.343901, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+176, 186189, 1, 1, 1, 0, 1367.842, -4341.304, 29.44495, 1.640607, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+177, 186189, 1, 1, 1, 0, 1367.559, -4341.842, 29.53806, 0.5759573, 0, 0, 0, 1, 120, 255, 1), -- Complimentary Brewfest Sampler (Area: Durotar)
(@OGUID+178, 195265, 1, 1, 1, 0, 1461.62, -4412.87, 25.3307, 6.265733, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+179, 195273, 1, 1, 1, 0, 1443.443, -4367.59, 29.6701, 3.231614, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+180, 195273, 1, 1, 1, 0, 1442.51, -4359.335, 29.7922, 3.351047, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+181, 195265, 1, 1, 1, 0, 1438.06, -4360.26, 25.3141, 6.265733, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+182, 195273, 1, 1, 1, 0, 1422.774, -4420.733, 29.58182, 0.2389043, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+183, 195265, 1, 1, 1, 0, 1431.02, -4429.32, 25.3084, 0.6981314, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+184, 195273, 1, 1, 1, 0, 1423.818, -4428.922, 29.56695, 0.1689689, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+185, 195265, 1, 1, 1, 0, 1440.91, -4431.95, 25.3092, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+186, 195265, 1, 1, 1, 0, 1430.48, -4426.53, 25.3069, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+187, 195260, 1, 1, 1, 0, 1511, -4353.71, 21.8799, 5.742135, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+188, 195260, 1, 1, 1, 0, 1514.98, -4347.08, 21.8799, 5.742135, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+189, 195260, 1, 1, 1, 0, 1519.73, -4346.31, 21.8991, 4.502952, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+190, 195273, 1, 1, 1, 0, 1537.53, -4371.99, 26.2845, 4.97419, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+191, 186717, 1, 1, 1, 0, 1610.788, -4175.733, 50.69487, 3.717554, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+192, 186717, 1, 1, 1, 0, 1566.519, -4409.335, 16.26762, 2.722713, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+193, 186717, 1, 1, 1, 0, 1563.807, -4394.624, 16.38291, 3.752462, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+194, 186717, 1, 1, 1, 0, 1600.594, -4160.323, 49.77016, 4.223697, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+195, 195256, 1, 1, 1, 0, 1546.19, -4358.04, 18.0411, 5.864307, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+196, 195256, 1, 1, 1, 0, 1543.31, -4363.78, 20.5475, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+197, 195256, 1, 1, 1, 0, 1537.75, -4375.94, 17.675, 5.061456, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+198, 186717, 1, 1, 1, 0, 1610.016, -4152.147, 49.28722, 0.6806767, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+199, 186717, 1, 1, 1, 0, 1585.036, -4400.337, 15.98898, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+200, 195256, 1, 1, 1, 0, 1617.39, -4414.44, 14.8831, 1.658062, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+201, 195256, 1, 1, 1, 0, 1607.73, -4383.83, 20.7904, 3.630291, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+202, 195256, 1, 1, 1, 0, 1569.382, -4382.37, 16.33681, 4.01426, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+203, 195263, 1, 1, 1, 0, 1611.72, -4426.97, 18.535, 1.727875, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+204, 195263, 1, 1, 1, 0, 1619.52, -4419.09, 18.1349, 3.019413, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+205, 195253, 1, 1, 1, 0, 1616.55, -4423.98, 27.1833, 2.35619, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+206, 195266, 1, 1, 1, 0, 1568.66, -4430.4, 22.4667, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Orgrimmar)
(@OGUID+207, 195266, 1, 1, 1, 0, 1572.11, -4429.4, 22.3762, 1.902409, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Orgrimmar)
(@OGUID+208, 195273, 1, 1, 1, 0, 1577.89, -4432.95, 19.1578, 1.413715, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+209, 195273, 1, 1, 1, 0, 1565.72, -4436.29, 19.3699, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+210, 195256, 1, 1, 1, 0, 1563.94, -4429.79, 14.3131, 1.553341, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+211, 195260, 1, 1, 1, 0, 1639.224, -4444.653, 18.51654, 5.358162, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+212, 195260, 1, 1, 1, 0, 1642.95, -4446.1, 26.2784, 2.146753, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+213, 195260, 1, 1, 1, 0, 1582.68, -4460.99, 23.1665, 1.780234, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+214, 195260, 1, 1, 1, 0, 1583.29, -4463.08, 17.241, 1.797689, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+215, 195260, 1, 1, 1, 0, 1635.714, -4448.338, 18.51783, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+216, 195260, 1, 1, 1, 0, 1576.56, -4462.54, 23.1665, 1.832595, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+217, 195256, 1, 1, 1, 0, 1556.81, -4331.15, 22.687, 5.759588, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+218, 195273, 1, 1, 1, 0, 1663.82, -4433.52, 24.727, 2.844883, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+219, 195273, 1, 1, 1, 0, 1670.95, -4423.82, 25.0509, 2.146753, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+220, 195260, 1, 1, 1, 0, 1577.53, -4464.76, 17.2691, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+221, 195260, 1, 1, 1, 0, 1580.1, -4464.06, 17.2387, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+222, 195256, 1, 1, 1, 0, 1662.05, -4339.31, 63.585, 6.073746, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+223, 195253, 1, 1, 1, 0, 1586.6, -4311.75, 28.1846, 4.747296, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+224, 195256, 1, 1, 1, 0, 1668.09, -4351.07, 63.585, 1.134463, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+225, 195256, 1, 1, 1, 0, 1593.26, -4310.62, 20.6237, 4.956738, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+226, 186717, 1, 1, 1, 0, 1929.738, -4283.722, 26.04098, 4.433136, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+227, 195273, 1, 1, 1, 0, 1665.35, -4338.9, 69.0835, 0.4712385, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+228, 186717, 1, 1, 1, 0, 1932.47, -4270.884, 28.41197, 4.433136, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+229, 195273, 1, 1, 1, 0, 1670.54, -4347.97, 69.057, 0.5235979, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+230, 195253, 1, 1, 1, 0, 1667.93, -4343.41, 73.0142, 0.5235979, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+231, 186717, 1, 1, 1, 0, 1908.151, -4279.316, 27.85269, 2.722713, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+232, 186717, 1, 1, 1, 0, 1910.431, -4264.191, 29.54248, 3.211419, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+233, 195256, 1, 1, 1, 0, 1738.08, -4399.5, 36.5337, 3.228859, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+234, 195263, 1, 1, 1, 0, 1753.66, -4387.6, 44.4203, 2.164206, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+235, 195256, 1, 1, 1, 0, 1747.04, -4412.49, 36.9625, 4.32842, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+236, 195263, 1, 1, 1, 0, 1747.46, -4391.86, 44.4295, 2.164206, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+237, 195263, 1, 1, 1, 0, 1756.81, -4405.87, 44.3153, 5.410522, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+238, 195263, 1, 1, 1, 0, 1763.08, -4401.58, 44.2932, 5.323256, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+239, 195253, 1, 1, 1, 0, 1799.31, -4370.67, 107.968, 1.029743, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+240, 186717, 1, 1, 1, 0, 1936.205, -4670.528, 33.31038, 2.007128, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+241, 186717, 1, 1, 1, 0, 1917.964, -4672.924, 34.47301, 1.396262, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+242, 186717, 1, 1, 1, 0, 1941.819, -4696.866, 35.99006, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- Brewfest Banner (Area: Orgrimmar)
(@OGUID+243, 195256, 1, 1, 1, 0, 1869.7, -4520.36, 24.5879, 3.38594, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+244, 195273, 1, 1, 1, 0, 1934.88, -4594.59, 41.6132, 2.111848, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+245, 195273, 1, 1, 1, 0, 1888.52, -4600.31, 41.4436, 5.358162, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+246, 195273, 1, 1, 1, 0, 1999.17, -4668.81, 30.5471, 4.049168, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+247, 195256, 1, 1, 1, 0, 1904.03, -4673.02, 35.3935, 0.5759573, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+248, 195273, 1, 1, 1, 0, 2034.51, -4670.44, 34.9736, 4.049168, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+249, 195253, 1, 1, 1, 0, 2037.28, -4676.05, 42.3894, 3.525572, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+250, 195273, 1, 1, 1, 0, 1900.76, -4678.78, 39.0823, 5.585054, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+251, 195263, 1, 1, 1, 0, 1900.32, -4687.98, 39.1395, 0.7679439, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+252, 195273, 1, 1, 1, 0, 2038.8, -4681.95, 35.0789, 2.932139, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+253, 195273, 1, 1, 1, 0, 1907.4, -4380.61, 46.3477, 5.009095, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+254, 195273, 1, 1, 1, 0, 1900.04, -4382.09, 46.428, 5.009095, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+255, 195273, 1, 1, 1, 0, 1886.2, -4281.51, 28.7554, 4.06662, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+256, 195273, 1, 1, 1, 0, 1904.11, -4364.18, 46.0628, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+257, 195273, 1, 1, 1, 0, 1896.69, -4365.69, 46.2012, 1.884953, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+258, 195273, 1, 1, 1, 0, 1860.77, -4291.64, 31.619, 0.05235888, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+259, 195263, 1, 1, 1, 0, 1917.9, -4231.13, 39.3524, 1.186823, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+260, 195266, 1, 1, 1, 0, 1919.79, -4232.33, 42.3856, 1.082103, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Orgrimmar)
(@OGUID+261, 195256, 1, 1, 1, 0, 1916.9, -4227.49, 37.0792, 0.8552105, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+262, 195273, 1, 1, 1, 0, 1747.47, -4198.38, 54.296, 4.450591, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+263, 195273, 1, 1, 1, 0, 1700.5, -4275.99, 37.3166, 3.874631, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+264, 195273, 1, 1, 1, 0, 1695.14, -4271.15, 37.3081, 4.049168, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+265, 195256, 1, 1, 1, 0, 1642.97, -4230.48, 52.0428, 4.101525, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+266, 195263, 1, 1, 1, 0, 1600.01, -4210.42, 57.4412, 5.323256, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+267, 195256, 1, 1, 1, 0, 1707.42, -4308.01, 31.2276, 5.480334, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+268, 195263, 1, 1, 1, 0, 1583.82, -4223.69, 57.41, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Square, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+269, 195256, 1, 1, 1, 0, 1574.01, -4217.67, 53.821, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+270, 195266, 1, 1, 1, 0, 1577.35, -4151.89, 55.8239, 4.01426, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer - Brewfest (Area: Orgrimmar)
(@OGUID+271, 195256, 1, 1, 1, 0, 1582.07, -4155.17, 51.7481, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+272, 195256, 1, 1, 1, 0, 1593.17, -4162.67, 51.7461, 5.340709, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+273, 195256, 1, 1, 1, 0, 1583.23, -4173.9, 51.7481, 0.1745321, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+274, 195256, 1, 1, 1, 0, 1535.88, -4203.01, 52.8145, 1.06465, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+275, 195253, 1, 1, 1, 0, 1640.07, -4121.75, 67.0279, 3.438303, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+276, 195260, 1, 1, 1, 0, 1730, -4078.51, 71.4373, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+277, 195256, 1, 1, 1, 0, 1727.25, -4065.76, 49.2647, 2.076939, 0, 0, 0, 1, 120, 255, 1), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+278, 195273, 1, 1, 1, 0, 1709.2, -4085.52, 51.6926, 2.897245, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+279, 195253, 1, 1, 1, 0, 1734.69, -4078.68, 58.7363, 1.902409, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar)
(@OGUID+280, 195265, 1, 1, 1, 0, 1737.41, -4069.72, 48.4278, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+281, 195273, 1, 1, 1, 0, 1740.31, -4076.71, 55.632, 1.937312, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+282, 195260, 1, 1, 1, 0, 1741.14, -4080.51, 69.1055, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+283, 195260, 1, 1, 1, 0, 1728.76, -4081.26, 71.3519, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+284, 195260, 1, 1, 1, 0, 1742.61, -4084.45, 69.1054, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar)
(@OGUID+285, 195273, 1, 1, 1, 0, 1729.18, -4080.59, 56.016, 1.937312, 0, 0, 0, 1, 120, 255, 1), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar)
(@OGUID+286, 195265, 1, 1, 1, 0, 1738.93, -4070.35, 49.3566, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+287, 195265, 1, 1, 1, 0, 1739.49, -4068.92, 48.1075, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Standing, Large - Brewfest (Area: Orgrimmar)
(@OGUID+288, 195265, 1, 1, 1, 0, 1738.97, -4070.38, 48.1077, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Standing; Large - Brewfest (Area: Orgrimmar)
(@OGUID+289, 186331, 1, 1, 1, 0, 1177.543, -4237.952, 23.5727, 1.082103, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+290, 186331, 1, 1, 1, 0, 1217.222, -4090.111, 21.98721, 5.515242, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+291, 186331, 1, 1, 1, 0, 1169.443, -4096.717, 17.99499, 4.468043, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+293, 186331, 1, 1, 1, 0, 1215.594, -4134.337, 23.4429, 0.9773831, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+294, 186331, 1, 1, 1, 0, 1177.543, -4237.952, 23.5727, 1.082103, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+295, 186331, 1, 1, 1, 0, 1210.561, -4333.396, 21.27718, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+296, 186331, 1, 1, 1, 0, 1315.767, -4651.978, 21.71007, 5.148723, 0, 0, 0, 1, 120, 255, 1), -- Apple Trap (Area: -Unknown-)
(@OGUID+297, 186331, 1, 1, 1, 0, 1327.163, -4557.806, 26.31773, 6.03884, 0, 0, 0, 1, 120, 255, 1); -- Apple Trap (Area: -Unknown-)

DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+76;
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
(24, @CGUID+76);

DELETE FROM `game_event_creature` WHERE `guid` IN (309984, 309997, 309998) AND `eventEntry`=24;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(-24, 309984),
(-24, 309997),
(-24, 309998);

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+297 AND `eventEntry`=24;
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
(24, @OGUID+293),
(24, @OGUID+294),
(24, @OGUID+295),
(24, @OGUID+296),
(24, @OGUID+297);

DELETE FROM `creature_template_addon` WHERE `entry` IN (24527, 24510, 24497, 24766, 24109, 24108, 24463, 27707, 24462, 24711, 23606, 23605, 24501, 23808, 24657, 23488, 24492, 23511, 23703, 24498, 23685, 23603, 23696, 24493, 24495, 23604, 23533, 24499, 23706);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(24527, 0, 0x0, 0x101, '44067'), -- Bok Dropcertain - Supplier Mark
(24510, 0, 0x0, 0x1, '44068'), -- Driz Tumblequick - Base Camp Mark
(24497, 0, 0x0, 0x1, ''), -- Ram Master Ray
(24766, 0, 0x0, 0x1, ''), -- [DND] Brewfest Face Me Bunny
(24109, 0, 0x0, 0x1, ''), -- [DND] Brewfest Target Dummy Move To Target
(24108, 0, 0x0, 0x1, ''), -- Self-Turning and Oscillating Utility Target
(24463, 0, 0x0, 0x1, ''), -- Swift Racing Ram
(27707, 0, 0x0, 0x1, ''), -- Great Brewfest Kodo
(24462, 0, 0x0, 0x1, ''), -- Racing Ram
(24711, 0, 0x0, 0x1, ''), -- Tapper Swindlekeg
(23606, 0, 0x0, 0x1, ''), -- Suntouched Apprentice
(23605, 0, 0x0, 0x1, ''), -- Bron
(24501, 0, 0x0, 0x1, ''), -- Drohn's Distillery Apprentice
(23808, 0, 0x0, 0x1, ''), -- [DND] Brewfest Keg Move to Target
(24657, 0, 0x0, 0x1, ''), -- Glodrak Huntsniper
(23488, 0, 0x0, 0x1, ''), -- Brewfest Crowd
(24492, 0, 0x0, 0x1, ''), -- Drohn's Distillery Barker
(23511, 0, 0x0, 0x101, ''), -- Gordok Brew Apprentice
(23703, 0, 0x0, 0x1, ''), -- [DND] Brewfest Dark Iron Event Generator
(24498, 0, 0x0, 0x1, ''), -- Cort Gorestein
(23685, 0, 0x0, 0x101, ''), -- Gordok Brew Barker
(23603, 0, 0x0, 0x1, ''), -- Uta Roughdough
(23696, 0, 0x0, 0x101, ''), -- Gordok Brew Chief
(24493, 0, 0x0, 0x1, ''), -- T'chali's Voodoo Brewery Barker
(24495, 0, 0x0, 0x1, ''), -- Blix Fixwidget
(23604, 0, 0x0, 0x1, ''), -- Agnes Farwithers
(23533, 0, 0x0, 0x1, ''), -- T'chali's Voodoo Brewery Apprentice
(24499, 0, 0x0, 0x1, ''), -- Ja'ron
(23706, 0, 0x0, 0x1, ''); -- Gordok Festive Keg

DELETE FROM `npc_vendor` WHERE `entry` IN (23533, 23603, 23604, 23605, 23606, 24495, 24501, 23511);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 23533 (T'chali's Voodoo Brewery Apprentice)
(23533, 34020, 1, 0, 0, 1), -- Jungle River Water
(23533, 34021, 2, 0, 0, 1), -- Brewdoo Magic
(23533, 34022, 3, 0, 0, 1), -- Stout Shrunken Head
(23533, 46401, 4, 0, 0, 1), -- Crimson Stripe
-- 23603 (Uta Roughdough)
(23603, 33043, 1, 0, 0, 1), -- The Essential Brewfest Pretzel
(23603, 4540, 2, 0, 0, 1), -- Tough Hunk of Bread
(23603, 4541, 3, 0, 0, 1), -- Freshly Baked Bread
(23603, 4542, 4, 0, 0, 1), -- Moist Cornbread
(23603, 4544, 5, 0, 0, 1), -- Mulgore Spice Bread
(23603, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(23603, 8950, 7, 0, 0, 1), -- Homemade Cherry Pie
(23603, 27855, 8, 0, 0, 1), -- Mag'har Grainbread
(23603, 33449, 9, 0, 0, 1), -- Crusty Flatbread
(23603, 35950, 10, 0, 0, 1), -- Sweet Potato Bread
(23603, 58260, 11, 0, 0, 1), -- Pine Nut Bread
(23603, 58261, 12, 0, 0, 1), -- Buttery Wheat Roll
(23603, 82450, 13, 0, 0, 1), -- Cornmeal Biscuit
(23603, 82451, 14, 0, 0, 1), -- Frybread
-- 23604 (Agnes Farwithers)
(23604, 34065, 1, 0, 0, 1), -- Spiced Onion Cheese
(23604, 2070, 2, 0, 0, 1), -- Darnassian Bleu
(23604, 414, 3, 0, 0, 1), -- Dalaran Sharp
(23604, 422, 4, 0, 0, 1), -- Dwarven Mild
(23604, 1707, 5, 0, 0, 1), -- Stormwind Brie
(23604, 3927, 6, 0, 0, 1), -- Fine Aged Cheddar
(23604, 8932, 7, 0, 0, 1), -- Alterac Swiss
(23604, 27857, 8, 0, 0, 1), -- Garadar Sharp
(23604, 33443, 9, 0, 0, 1), -- Sour Goat Cheese
(23604, 35952, 10, 0, 0, 1), -- Briny Hardcheese
(23604, 58258, 11, 0, 0, 1), -- Smoked String Cheese
(23604, 58259, 12, 0, 0, 1), -- Highland Sheep Cheese
(23604, 81922, 13, 0, 0, 1), -- Redridge Roquefort
(23604, 81921, 14, 0, 0, 1), -- Chilton Stilton
-- 23605 (Bron)
(23605, 34063, 1, 0, 0, 1), -- Dried Sausage
(23605, 34064, 2, 0, 0, 1), -- Succulent Sausage
(23605, 33023, 3, 0, 0, 1), -- Savory Sausage
(23605, 33024, 4, 0, 0, 1), -- Pickled Sausage
(23605, 33025, 5, 0, 0, 1), -- Spicy Smoked Sausage
(23605, 33026, 6, 0, 0, 1), -- The Golden Link
(23605, 117, 7, 0, 0, 1), -- Tough Jerky
(23605, 2287, 8, 0, 0, 1), -- Haunch of Meat
(23605, 3770, 9, 0, 0, 1), -- Mutton Chop
(23605, 3771, 10, 0, 0, 1), -- Wild Hog Shank
(23605, 4599, 11, 0, 0, 1), -- Cured Ham Steak
(23605, 8952, 12, 0, 0, 1), -- Roasted Quail
(23605, 27854, 13, 0, 0, 1), -- Smoked Talbuk Venison
(23605, 33454, 14, 0, 0, 1), -- Salted Venison
(23605, 35953, 15, 0, 0, 1), -- Mead Basted Caribou
(23605, 58268, 16, 0, 0, 1), -- Roasted Beef
(23605, 58269, 17, 0, 0, 1), -- Massive Turkey Leg
(23605, 81917, 18, 0, 0, 1), -- Mutton Stew
(23605, 81918, 19, 0, 0, 1), -- Pickled Pig's Snout
-- 23606 (Suntouched Apprentice)
(23606, 2723, 1, 0, 0, 1), -- Bottle of Dalaran Noir
(23606, 2593, 2, 0, 0, 1), -- Flask of Stormwind Tawny
(23606, 2596, 3, 0, 0, 1), -- Skin of Dwarven Stout
(23606, 2594, 4, 0, 0, 1), -- Flagon of Dwarven Mead
(23606, 2595, 5, 0, 0, 1), -- Jug of Badlands Bourbon
(23606, 83095, 6, 0, 0, 1), -- Lagrave Stout
(23606, 82343, 7, 0, 0, 1), -- Lordaeron Lambic
(23606, 83094, 8, 0, 0, 1), -- Foote Tripel
(23606, 82344, 9, 0, 0, 1), -- Hearthglen Ambrosia
-- 24495 (Blix Fixwidget)
(24495, 33968, 1, 0, 2274, 1), -- Blue Brewfest Hat
(24495, 33864, 2, 0, 2274, 1), -- Brown Brewfest Hat
(24495, 33967, 3, 0, 2274, 1), -- Green Brewfest Hat
(24495, 33969, 4, 0, 2274, 1), -- Purple Brewfest Hat
(24495, 33863, 5, 0, 2276, 1), -- Brewfest Dress
(24495, 33966, 6, 0, 2275, 1), -- Brewfest Slippers
(24495, 33862, 7, 0, 2276, 1), -- Brewfest Regalia
(24495, 33868, 8, 0, 2275, 1), -- Brewfest Boots
(24495, 37599, 9, 0, 2276, 1), -- "Brew of the Month" Club Membership Form
(24495, 34008, 11, 0, 2275, 1), -- Blix's Eyesight Enhancing Romance Goggles
(24495, 39477, 12, 0, 2424, 1), -- Fresh Dwarven Brewfest Hops
(24495, 90426, 13, 0, 2398, 1), -- Brewhelm
(24495, 90427, 14, 0, 2275, 1), -- Pandaren Brewpack
(24495, 71137, 15, 0, 2276, 1), -- Brewfest Keg Pony
(24495, 33927, 16, 0, 2275, 1), -- Brewfest Pony Keg
(24495, 46707, 17, 0, 2275, 1), -- Pint-Sized Pink Pachyderm
(24495, 32233, 18, 0, 2276, 1), -- Wolpertinger's Tankard
(24495, 37750, 19, 0, 2398, 1), -- Fresh Brewfest Hops
(24495, 37816, 20, 0, 2399, 1), -- Preserved Brewfest Hops
-- 24501 (Drohn's Distillery Apprentice)
(24501, 34017, 1, 0, 0, 1), -- Small Step Brew
(24501, 34018, 2, 0, 0, 1), -- Long Stride Brew
(24501, 34019, 3, 0, 0, 1), -- Path of Brew
(24501, 46402, 4, 0, 0, 1), -- Promise of the Pandaren
-- 23511 (Gordok Brew Apprentice)
(23511, 33034, 1, 0, 0, 1), -- Gordok Grog
(23511, 33035, 2, 0, 0, 1), -- Ogre Mead
(23511, 33036, 3, 0, 0, 1), -- Mudder's Milk
(23511, 46403, 4, 0, 0, 1); -- Chuganpug's Delight
