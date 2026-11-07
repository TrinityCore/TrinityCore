SET @CGUID := 7003273;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+101;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -248.017364501953125, 2352.407958984375, 62.87564468383789062, 3.081491470336914062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+1, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -259.173614501953125, 2356.928955078125, 61.37173843383789062, 0.363085150718688964, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+2, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -257.532989501953125, 2395.404541015625, 72.11810302734375, 4.989075183868408203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+3, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -290.9132080078125, 2320.600830078125, 63.23931121826171875, 1.478368163108825683, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+4, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -288.79339599609375, 2319.0869140625, 63.17291259765625, 0.699583113193511962, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+5, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -254.850692749023437, 2382.564208984375, 67.54994964599609375, 5.054188251495361328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+6, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -250.5, 2334.958251953125, 61.47085952758789062, 5.079715251922607421, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+7, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -251.479171752929687, 2350.29345703125, 62.23786163330078125, 2.467104434967041015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+8, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -301.138885498046875, 2346.59716796875, 64.334320068359375, 6.047640323638916015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+9, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -234.107635498046875, 2361.04345703125, 70.0010223388671875, 4.519479751586914062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+10, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -283.71527099609375, 2354.671875, 63.92791748046875, 4.033522605895996093, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+11, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -275.501739501953125, 2380.673583984375, 67.3201141357421875, 6.083749294281005859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+12, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -274.73785400390625, 2377.501708984375, 66.693511962890625, 4.950794219970703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+13, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -278.48785400390625, 2371.732666015625, 65.03809356689453125, 0.330310553312301635, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+14, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -275.20660400390625, 2372.404541015625, 65.512542724609375, 0.177587702870368957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+15, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -271.289947509765625, 2375.123291015625, 65.60343170166015625, 4.672250747680664062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+16, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -279.248260498046875, 2376.01220703125, 65.73297882080078125, 0.100328005850315093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+17, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -271.484375, 2353.395751953125, 76.87457275390625, 5.788966178894042968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+18, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -240.510421752929687, 2378.163330078125, 72.236358642578125, 4.519479751586914062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+19, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -290.572906494140625, 2317.43408203125, 64.9517669677734375, 3.437305212020874023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+20, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -313.05902099609375, 2374.017333984375, 61.06576156616210937, 4.146316051483154296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+21, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -250.777786254882812, 2368.616455078125, 61.51596832275390625, 1.478428840637207031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+22, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -312.375, 2369.5244140625, 61.39560317993164062, 2.585978507995605468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+23, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -298.701385498046875, 2303.911376953125, 61.3016357421875, 0.652158200740814208, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+24, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -257.63714599609375, 2381.713623046875, 67.42078399658203125, 2.592519760131835937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+25, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -247.053817749023437, 2363.1181640625, 62.08816909790039062, 3.011483669281005859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+26, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -314.295135498046875, 2367.192626953125, 61.41523361206054687, 2.585978507995605468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+27, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -260.1875, 2364.100830078125, 61.33723831176757812, 2.402752876281738281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+28, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -252.208328247070312, 2356.739501953125, 61.95616912841796875, 5.136470794677734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+29, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -285.173614501953125, 2359.307373046875, 63.66244125366210937, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+30, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -281.723968505859375, 2365.736083984375, 63.51564407348632812, 2.585978507995605468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+31, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -287.51910400390625, 2318.260498046875, 63.11978912353515625, 1.28601384162902832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+32, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -299.151031494140625, 2386.890625, 61.6787567138671875, 6.069543838500976562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+33, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -284.348968505859375, 2365.210205078125, 63.62543869018554687, 5.160645961761474609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+34, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -249.59722900390625, 2381.2744140625, 66.4730377197265625, 4.802081584930419921, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+35, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -288.993072509765625, 2309.677001953125, 62.33449172973632812, 2.13262176513671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+36, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -238.958328247070312, 2378.35595703125, 72.05450439453125, 1.517837166786193847, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+37, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -242.857635498046875, 2278.572998046875, 56.69730377197265625, 4.043294906616210937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+38, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -250.168411254882812, 2348.6025390625, 61.59560775756835937, 4.086003780364990234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+39, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -263.321197509765625, 2370, 62.43521881103515625, 0.22725805640220642, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+40, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -244.89410400390625, 2350.036376953125, 62.69144058227539062, 1.478428840637207031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+41, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -259.689239501953125, 2305.032958984375, 63.98743820190429687, 2.011989831924438476, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+42, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -248.630203247070312, 2308.583251953125, 63.87073898315429687, 2.375813961029052734, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+43, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -273.91839599609375, 2282.232666015625, 59.21466827392578125, 3.087697505950927734, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+44, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -215.835067749023437, 2286.1806640625, 62.7799530029296875, 3.697027206420898437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+45, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -254.215286254882812, 2306.92529296875, 69.430694580078125, 1.46271669864654541, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+46, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -290.026031494140625, 2279.630126953125, 58.63593673706054687, 1.018799424171447753, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+47, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -228.142364501953125, 2378.177001953125, 71.01312255859375, 4.718141078948974609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+48, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -226.70660400390625, 2368.65283203125, 71.91766357421875, 3.522953033447265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+49, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -209.302078247070312, 2402.140625, 78.41228485107421875, 0.459695667028427124, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+50, 129886, 1643, 8721, 8721, '0', 0, 0, 0, 0, -236.96875, 2412.338623046875, 78.86785888671875, 5.712992191314697265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Rabbit (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+51, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -178.998260498046875, 2451.77783203125, 96.49987030029296875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+52, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -212.87847900390625, 2410.5400390625, 80.19142913818359375, 4.905102729797363281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+53, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -219.619796752929687, 2410.32470703125, 79.52257537841796875, 3.496132373809814453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+54, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -181.527786254882812, 2448.276123046875, 95.4117431640625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+55, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -175.413192749023437, 2388.763916015625, 72.04367828369140625, 2.799005746841430664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+56, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -182.145828247070312, 2453.71533203125, 96.4125213623046875, 0.377007484436035156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+57, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -215.074661254882812, 2414.802001953125, 81.325927734375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+58, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -217.1875, 2412.755126953125, 80.629119873046875, 2.297600984573364257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+59, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -185.423614501953125, 2452.720458984375, 96.0025177001953125, 2.638262748718261718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+60, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -226.229171752929687, 2397.079833984375, 93.12921142578125, 1.009299039840698242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+61, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -104.920143127441406, 2482.255126953125, 114.78314208984375, 0.932810485363006591, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+62, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -116.489593505859375, 2442.23779296875, 99.4659271240234375, 0.532619237899780273, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+63, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -213.510421752929687, 2440.397705078125, 87.9723663330078125, 0.60954219102859497, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+64, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -210.423614501953125, 2439.34375, 88.02120208740234375, 0.057635135948657989, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+65, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -206.37847900390625, 2436.201416015625, 88.23760986328125, 1.230524778366088867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+66, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -206.56597900390625, 2440.96875, 88.929931640625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+67, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -211.590286254882812, 2434.736083984375, 86.67578125, 0.86262822151184082, 120, 6, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+68, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -207.572921752929687, 2433.078125, 87.284698486328125, 1.217238664627075195, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+69, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -121.442710876464843, 2425.725830078125, 93.58391571044921875, 3.377142906188964843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+70, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -168.614578247070312, 2429.583251953125, 116.9599380493164062, 2.082644939422607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+71, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -93.0694427490234375, 2489.329833984375, 118.75439453125, 5.55127716064453125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+72, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -93.2135391235351562, 2465.2900390625, 109.235137939453125, 3.821393489837646484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+73, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -107.335067749023437, 2479.861083984375, 114.6367340087890625, 4.895513057708740234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+74, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -63.8489570617675781, 2505.8134765625, 125.7322769165039062, 0.687230825424194335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+75, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -22.7361106872558593, 2514.533935546875, 134.716949462890625, 0.602410554885864257, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+76, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -35.9236106872558593, 2510.799560546875, 130.0979461669921875, 0.470038354396820068, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+77, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -55.5572929382324218, 2498.661376953125, 123.5835952758789062, 5.852807044982910156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+78, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -34.5347213745117187, 2463.97216796875, 117.5094451904296875, 2.194599628448486328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+79, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, 25.05729103088378906, 2476.579833984375, 133.3482666015625, 4.460426807403564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+80, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -65.9652786254882812, 2498.90283203125, 123.7018966674804687, 0.785071730613708496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+81, 127808, 1643, 8721, 8721, '0', 0, 0, 0, 0, -54.9201393127441406, 2501.92529296875, 125.3840484619140625, 1.201155781745910644, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Fawn (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+82, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -18.307291030883789, 2522.952392578125, 139.2266693115234375, 3.544527530670166015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+83, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -2.09375, 2473.0556640625, 142.0468292236328125, 4.105377197265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+84, 127807, 1643, 8721, 8721, '0', 0, 0, 0, 0, -73.0208358764648437, 2502.710205078125, 124.5821533203125, 3.348693609237670898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Doe (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+85, 127801, 1643, 8721, 8721, '0', 0, 0, 0, 0, -12.9826393127441406, 2477.963623046875, 127.196533203125, 0.769550502300262451, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+86, 127806, 1643, 8721, 8721, '0', 0, 0, 0, 0, -35.8003463745117187, 2449.907958984375, 113.36004638671875, 1.95473790168762207, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mountain Greatstag (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+87, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -152.109375, 2372.904541015625, 75.1953277587890625, 3.03727126121520996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+88, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -321.180572509765625, 2363.611083984375, 60.5477294921875, 3.041397809982299804, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+89, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -292.430572509765625, 2405.1337890625, 64.52591705322265625, 3.588846683502197265, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+90, 129873, 1643, 8721, 8721, '0', 0, 0, 0, 0, -329.711822509765625, 2465.96533203125, 85.12066650390625, 5.260919570922851562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Ruin Sentinel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+91, 129873, 1643, 8721, 8721, '0', 0, 0, 0, 0, -376.914947509765625, 2335.3369140625, 85.16961669921875, 5.049091339111328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Ruin Sentinel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+92, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -319.265625, 2399.880126953125, 62.40819549560546875, 4.99767160415649414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+93, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -350.8125, 2373.1806640625, 60.85578155517578125, 4.168284416198730468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+94, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -318.8125, 2341.201416015625, 61.42816162109375, 4.204686164855957031, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+95, 129873, 1643, 8721, 8721, '0', 0, 0, 0, 0, -431.039947509765625, 2402.55908203125, 104.7013931274414062, 0.508233308792114257, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Ruin Sentinel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+96, 129888, 1643, 8721, 8721, '0', 0, 0, 0, 0, -341.810760498046875, 2444.032958984375, 65.043731689453125, 3.447429895401000976, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Rimed Peeper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+97, 129873, 1643, 8721, 8721, '0', 0, 0, 0, 0, -338.064239501953125, 2409.826416015625, 65.5396728515625, 4.568089485168457031, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Ruin Sentinel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+98, 128852, 1643, 8721, 8904, '0', 0, 0, 0, 0, -328.44097900390625, 2270.382080078125, 84.57648468017578125, 5.950843334197998046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+99, 128852, 1643, 8721, 8904, '0', 0, 0, 0, 0, -338.93402099609375, 2261.173583984375, 84.83089447021484375, 1.939924955368041992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+100, 128852, 1643, 8721, 8904, '0', 0, 0, 0, 0, -373.868072509765625, 2301.0244140625, 128.0042266845703125, 5.105090141296386718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Chillwind Hawk (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+101, 129771, 1643, 8721, 8904, '0', 0, 0, 0, 0, -256.244354248046875, 2394.38525390625, 71.18920135498046875, 3.660562992095947265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967); -- Athair (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 257499 - Forest Guardian)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+101;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+9, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+18, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+27, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+28, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+29, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+36, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+38, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''), -- Chillwind Hawk
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+73, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+74, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+76, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+84, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Mountain Doe - 123169 - Mod Scale 105-110%
(@CGUID+87, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''), -- Chillwind Hawk
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''); -- Chillwind Hawk

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (129771 /*129771 (Athair) - Forest Guardian*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(129771, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '257499'); -- 129771 (Athair) - Forest Guardian

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=129771 AND `DifficultyID`=0); -- 129771 (Athair) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=129771 AND `MenuID`=22634);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(129771, 22634, 61967); -- Athair

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (22634));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 22634, 0, 0, 0, 15, 0, 1024, 0, 0, '', 0, 'Player for which gossip text is shown class is part of classmask 1024');

UPDATE `gossip_menu` SET `VerifiedBuild`=61967 WHERE (`MenuID`=22634 AND `TextID`=34864);

-- Path for Athair
SET @ENTRY := 129771;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Athair - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -263.0486, 2390.427, 70.62732, NULL, 0),
(@PATH, 1, -271.36978, 2385.519, 68.67537, NULL, 0),
(@PATH, 2, -278.66666, 2383.3196, 66.7293, NULL, 0),
(@PATH, 3, -284.86285, 2381.4966, 65.009605, NULL, 0),
(@PATH, 4, -295.10245, 2372.816, 63.02745, NULL, 0),
(@PATH, 5, -305.14236, 2363.8455, 63.233566, NULL, 0),
(@PATH, 6, -310.56598, 2356.0278, 63.757217, NULL, 0),
(@PATH, 7, -311.46527, 2345.3074, 63.4551, NULL, 0),
(@PATH, 8, -309.2205, 2338.8542, 62.721394, NULL, 0),
(@PATH, 9, -305.5139, 2328.6719, 62.10858, NULL, 0),
(@PATH, 10, -302.80035, 2321.7014, 62.082268, NULL, 0),
(@PATH, 11, -298.06424, 2312.9792, 62.358334, NULL, 0),
(@PATH, 12, -292.19446, 2305.092, 61.94219, NULL, 0),
(@PATH, 13, -284.5625, 2296.3508, 61.35898, NULL, 0),
(@PATH, 14, -280.67535, 2290.962, 60.695404, NULL, 0),
(@PATH, 15, -275.75522, 2286.7986, 60.124084, NULL, 0),
(@PATH, 16, -273.07227, 2285.457, 60.548405, NULL, 0),
(@PATH, 17, -267.0486, 2282.448, 60.557785, NULL, 0),
(@PATH, 18, -257.93576, 2280.507, 59.98526, NULL, 0),
(@PATH, 19, -248.24826, 2283.665, 60.337368, NULL, 0),
(@PATH, 20, -240.59201, 2287.2517, 61.015423, NULL, 0),
(@PATH, 21, -234.96007, 2292.2222, 61.800323, NULL, 0),
(@PATH, 22, -232.41145, 2299.7327, 62.46541, NULL, 0),
(@PATH, 23, -229.8125, 2310.421, 64.05904, NULL, 0),
(@PATH, 24, -228.77951, 2315.302, 64.48692, NULL, 0),
(@PATH, 25, -225.53711, 2324.755, 64.271355, NULL, 0),
(@PATH, 26, -222.75174, 2335.6736, 64.23583, NULL, 0),
(@PATH, 27, -218.64062, 2344.1355, 65.11617, NULL, 0),
(@PATH, 28, -213.20486, 2352.1963, 66.16695, NULL, 0),
(@PATH, 29, -205.47395, 2362.0364, 66.52604, NULL, 0),
(@PATH, 30, -196.4375, 2369.717, 68.24368, NULL, 0),
(@PATH, 31, -192.25868, 2380.25, 69.2291, NULL, 0),
(@PATH, 32, -193.00868, 2390.4253, 71.97444, NULL, 0),
(@PATH, 33, -202.73785, 2395.4966, 75.35087, NULL, 0),
(@PATH, 34, -211.3802, 2394.6562, 75.936325, NULL, 0),
(@PATH, 35, -221.6632, 2396.467, 74.66867, NULL, 0),
(@PATH, 36, -227.625, 2398.559, 75.48683, NULL, 0),
(@PATH, 37, -232.52951, 2401.217, 76.277954, NULL, 0),
(@PATH, 38, -238.25694, 2403.7534, 75.62111, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@CGUID+101;
UPDATE `creature_template_addon` SET `PathId` = @PATH WHERE `entry` = 129771;

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+17;
SET @ENTRY := 128852;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -258.00867, 2346.1348, 76.87457, NULL, 0),
(@PATH, 1, -253.61414, 2331.472, 76.87457, NULL, 0),
(@PATH, 2, -260.875, 2317.9963, 76.87457, NULL, 0),
(@PATH, 3, -275.53796, 2313.6016, 76.87457, NULL, 0),
(@PATH, 4, -289.01367, 2320.8625, 76.87457, NULL, 0),
(@PATH, 5, -293.4082, 2335.5254, 76.87457, NULL, 0),
(@PATH, 6, -286.14734, 2349.0012, 76.87457, NULL, 0),
(@PATH, 7, -271.48438, 2353.3958, 76.87457, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+60;
SET @ENTRY := 128852;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8685, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -219.30132, 2408.0933, 93.12921, NULL, 0),
(@PATH, 1, -206.61487, 2410.9824, 93.12921, NULL, 0),
(@PATH, 2, -195.60138, 2404.0544, 93.12921, NULL, 0),
(@PATH, 3, -192.71239, 2391.368, 93.12921, NULL, 0),
(@PATH, 4, -199.64023, 2380.3545, 93.12921, NULL, 0),
(@PATH, 5, -212.32669, 2377.4656, 93.12921, NULL, 0),
(@PATH, 6, -223.34018, 2384.3933, 93.12921, NULL, 0),
(@PATH, 7, -226.22917, 2397.0798, 93.12921, NULL, 0),
(@PATH, 8, -219.30132, 2408.0933, 93.12921, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+70;
SET @ENTRY := 128852;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8686, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -177.98627, 2446.2651, 116.95994, NULL, 0),
(@PATH, 1, -172.81712, 2464.688, 116.95994, NULL, 0),
(@PATH, 2, -156.13516, 2474.0596, 118.37039, NULL, 0),
(@PATH, 3, -137.71245, 2468.8904, 116.95994, NULL, 0),
(@PATH, 4, -128.34076, 2452.2085, 116.95994, NULL, 0),
(@PATH, 5, -133.5099, 2433.786, 116.95994, NULL, 0),
(@PATH, 6, -150.19186, 2424.414, 116.95994, NULL, 0),
(@PATH, 7, -168.61458, 2429.5833, 116.95994, NULL, 0),
(@PATH, 8, -177.98627, 2446.2651, 116.95994, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+83;
SET @ENTRY := 128852;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -10.825282, 2460.483, 142.04683, NULL, 0),
(@PATH, 1, -25.889706, 2457.7666, 142.04683, NULL, 0),
(@PATH, 2, -38.462494, 2466.4983, 142.04683, NULL, 0),
(@PATH, 3, -41.178673, 2481.5627, 142.04683, NULL, 0),
(@PATH, 4, -32.447136, 2494.1355, 142.04683, NULL, 0),
(@PATH, 5, -17.382706, 2496.8516, 142.04683, NULL, 0),
(@PATH, 6, -4.809923, 2488.12, 142.04683, NULL, 0),
(@PATH, 7, -2.09375, 2473.0557, 142.04683, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+98;
SET @ENTRY := 128852;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -313.97125, 2265.388, 84.576485, NULL, 0),
(@PATH, 1, -300.20822, 2272.0881, 84.576485, NULL, 0),
(@PATH, 2, -295.21405, 2286.5579, 84.576485, NULL, 0),
(@PATH, 3, -301.9143, 2300.321, 84.576485, NULL, 0),
(@PATH, 4, -316.38403, 2305.3152, 84.576485, NULL, 0),
(@PATH, 5, -330.14706, 2298.6147, 84.576485, NULL, 0),
(@PATH, 6, -335.14124, 2284.145, 84.576485, NULL, 0),
(@PATH, 7, -328.44098, 2270.382, 84.576485, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+100;
SET @ENTRY := 128852;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -368.0102, 2286.8823, 128.00423, NULL, 0),
(@PATH, 1, -353.86807, 2281.0244, 128.00423, NULL, 0),
(@PATH, 2, -339.72595, 2286.8823, 128.00423, NULL, 0),
(@PATH, 3, -333.86807, 2301.0244, 128.00423, NULL, 0),
(@PATH, 4, -339.72592, 2315.1665, 128.00423, NULL, 0),
(@PATH, 5, -353.86807, 2321.0244, 128.00423, NULL, 0),
(@PATH, 6, -368.0102, 2315.1665, 128.00423, NULL, 0),
(@PATH, 7, -373.86807, 2301.0244, 128.00423, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Mountain Greatstag
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+15;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+15, @CGUID+15, 0, 0, 515, 0, 0),
(@CGUID+15, @CGUID+12, 3, 320, 515, 0, 0),
(@CGUID+15, @CGUID+14, 3, 40, 515, 0, 0),
(@CGUID+15, @CGUID+11, 6, 320, 515, 0, 0),
(@CGUID+15, @CGUID+13, 6, 40, 515, 0, 0),
(@CGUID+15, @CGUID+16, 9, 40, 515, 0, 0);

SET @MOVERGUID := @CGUID+15;
SET @ENTRY := 127806;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Mountain Greatstag - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -269.79102, 2363.5017, 62.128517, NULL, 0),
(@PATH, 1, -269.75, 2357.8784, 61.71071, NULL, 0),
(@PATH, 2, -267.1771, 2346.3525, 61.38913, NULL, 0),
(@PATH, 3, -253.80904, 2336.7952, 61.38713, NULL, 0),
(@PATH, 4, -247.48438, 2334.0347, 61.40633, NULL, 0),
(@PATH, 5, -241.11806, 2330.6892, 61.962967, NULL, 0),
(@PATH, 6, -235.01389, 2326.481, 63.332283, NULL, 0),
(@PATH, 7, -232.71529, 2320.434, 64.25597, NULL, 0),
(@PATH, 8, -233.6302, 2313.1355, 64.55538, NULL, 0),
(@PATH, 9, -233.90625, 2305.677, 63.61457, NULL, 0),
(@PATH, 10, -240.96355, 2305.8645, 64.22283, NULL, 0),
(@PATH, 11, -253.34895, 2318.1667, 61.889046, NULL, 0),
(@PATH, 12, -264.30902, 2321.5557, 61.38821, NULL, 0),
(@PATH, 13, -281.06076, 2332.9844, 61.38644, NULL, 0),
(@PATH, 14, -287.63715, 2338.0557, 61.60556, NULL, 0),
(@PATH, 15, -293.1771, 2345.5156, 64.0586, NULL, 0),
(@PATH, 16, -294.66147, 2350.25, 64.68876, NULL, 0),
(@PATH, 17, -296.87848, 2357.7222, 63.645245, NULL, 0),
(@PATH, 18, -297.99133, 2370.3403, 62.888367, NULL, 0),
(@PATH, 19, -293.8507, 2378.7292, 63.225227, NULL, 0),
(@PATH, 20, -286.65103, 2383.0034, 65.054825, NULL, 0),
(@PATH, 21, -280.6979, 2382.2395, 65.94957, NULL, 0),
(@PATH, 22, -276.36633, 2377.4565, 66.54025, NULL, 408),
(@PATH, 23, -271.49478, 2370.1875, 64.05723, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
