SET @CGUID := 7001527;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+89;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -79.095489501953125, 2095.776123046875, 46.8554229736328125, 1.949306130409240722, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+1, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -60.2725715637207031, 2112.897705078125, 46.42088699340820312, 0.636953115463256835, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+2, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -54.6649322509765625, 2089.529541015625, 46.70103073120117187, 2.143753290176391601, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -100.651039123535156, 2070.798583984375, 46.37363815307617187, 3.948710918426513671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -40.0243072509765625, 2076.536376953125, 47.01972579956054687, 0.96297997236251831, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -40.1666679382324218, 2052.0625, 47.02152633666992187, 1.299440264701843261, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -15.7100696563720703, 2051.757080078125, 47.02509689331054687, 1.984461188316345214, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -110.296882629394531, 2075.201416015625, 47.3240966796875, 0.603575468063354492, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+8, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -24.2847232818603515, 2071.338623046875, 47.02206802368164062, 1.966065049171447753, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+9, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -89.7065963745117187, 2086.807373046875, 47.12377548217773437, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+10, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -57.171875, 2120.354248046875, 46.7067108154296875, 1.897761464118957519, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+11, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -90.5277786254882812, 2092.1337890625, 49.1483306884765625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+12, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -70.861114501953125, 2098.572998046875, 46.68302536010742187, 5.311376571655273437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -91.6614608764648437, 2079.421875, 47.01313018798828125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+14, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -71.7881927490234375, 2093.69970703125, 56.98774337768554687, 0.160736903548240661, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+15, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -46.0815963745117187, 2099.4619140625, 46.90613555908203125, 3.506556034088134765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -75.3541641235351562, 2050.47216796875, 51.67226409912109375, 4.329783439636230468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+17, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -101.239593505859375, 2123.882080078125, 64.42724609375, 5.25558328628540039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+18, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -28.8645839691162109, 2032.296875, 48.99341964721679687, 2.465610980987548828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+19, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -22.026041030883789, 2076.645751953125, 56.21396636962890625, 3.179105997085571289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+20, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -102.65625, 2121.46875, 46.543243408203125, 1.398612260818481445, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+21, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -76.3194427490234375, 2117.578125, 63.74510955810546875, 5.852974891662597656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+22, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -109.321182250976562, 2161.54345703125, 47.82781600952148437, 5.291689395904541015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -99.1597213745117187, 2142.234375, 47.43024444580078125, 1.080950498580932617, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+24, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -99.6805572509765625, 2146.220458984375, 61.28895187377929687, 6.120906829833984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+25, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -102.501739501953125, 2223.3369140625, 51.361907958984375, 4.864963054656982421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+26, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -99.517364501953125, 2151.33154296875, 61.43240737915039062, 0.312074542045593261, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+27, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -113.119789123535156, 2215.265625, 47.41217803955078125, 4.188872337341308593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+28, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -54.1493072509765625, 2141.40283203125, 46.63560104370117187, 4.981966495513916015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -134.751739501953125, 2237.725830078125, 56.09040069580078125, 2.69293379783630371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+30, 129794, 1643, 8721, 9032, '0', 0, 0, 0, 0, -1.09375, 2206.5625, 36.53562164306640625, 2.932135581970214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Deep Woods Leaper (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+31, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -74.7222213745117187, 2142.86279296875, 63.03339385986328125, 5.736224174499511718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+32, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -94.767364501953125, 2158.116455078125, 46.25330352783203125, 0.139805808663368225, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -53.8958320617675781, 2135.975830078125, 47.72234725952148437, 1.24516308307647705, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+34, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -129.467010498046875, 2218.3994140625, 48.02693939208984375, 0.166606292128562927, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+35, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -78.5277786254882812, 2251.671875, 47.81792449951171875, 1.972308158874511718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+36, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -96.0503463745117187, 2291.942626953125, 52.07654571533203125, 5.861756801605224609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+37, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -112.559028625488281, 2249.092041015625, 46.76059722900390625, 3.2566375732421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+38, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -105.878471374511718, 2285.994873046875, 46.54139328002929687, 5.192982673645019531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+39, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -137.555557250976562, 2264.583251953125, 50.49085235595703125, 3.901584148406982421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+40, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -122.442710876464843, 2280.15625, 68.9797210693359375, 0.558328628540039062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+41, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -113.708343505859375, 2248.145751953125, 46.8993988037109375, 2.068462848663330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+42, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -128.381942749023437, 2294.694580078125, 49.49239730834960937, 5.065996646881103515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+43, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -104.175346374511718, 2298.553955078125, 73.63836669921875, 1.956419825553894042, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+44, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -68.8055572509765625, 2281.19970703125, 51.77367401123046875, 5.049124717712402343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+45, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -115.300346374511718, 2251.395751953125, 46.90128326416015625, 5.484583377838134765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+46, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -89.28125, 2267.178955078125, 73.80377197265625, 1.692471981048583984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+47, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -138.685760498046875, 2266.428955078125, 50.93717575073242187, 3.137156963348388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+48, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -118.536460876464843, 2247.359375, 72.22231292724609375, 6.061508655548095703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed) (possible waypoints or random movement)
(@CGUID+49, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -52.0138893127441406, 1955.3646240234375, 32.84583282470703125, 6.129387855529785156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+50, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -46.0659713745117187, 1926.1597900390625, 33.12993621826171875, 5.531644344329833984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+51, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -62.0104179382324218, 1984.407958984375, 33.07831573486328125, 3.402172565460205078, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+52, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -22.0347232818603515, 1925.04345703125, 36.35385894775390625, 0.69339001178741455, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed) (possible waypoints or random movement)
(@CGUID+53, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -0.82291668653488159, 1965.779541015625, 34.29513931274414062, 3.749925613403320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+54, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -79.032989501953125, 2005.3541259765625, 33.58329010009765625, 4.325376510620117187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+55, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -36.7552070617675781, 1994.6041259765625, 33.67110443115234375, 3.102360963821411132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+56, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -0.24131944775581359, 2005.857666015625, 35.54758071899414062, 1.379144549369812011, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+57, 124548, 1643, 8721, 9032, '0', 0, 0, 0, 0, -4.51736116409301757, 1949.6353759765625, 33.75843048095703125, 2.600223064422607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Betsy (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247395 - Possessed)
(@CGUID+58, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -105.104156494140625, 1978.045166015625, 33.47491073608398437, 0.233164533972740173, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+59, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -105.730903625488281, 1968.8663330078125, 32.99146270751953125, 1.569582104682922363, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+60, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -82.2083358764648437, 2013.892333984375, 33.85077667236328125, 2.663702964782714843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+61, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -114.375, 1978.623291015625, 34.498504638671875, 0.961605668067932128, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+62, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -1.3472222089767456, 1950.2117919921875, 33.21432876586914062, 0.78809291124343872, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+63, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -17.432291030883789, 1944.04345703125, 34.67128753662109375, 2.380440950393676757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+64, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -4.34722232818603515, 1959.59033203125, 34.6494293212890625, 3.020150423049926757, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+65, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, 1.75, 1967.5382080078125, 34.47412872314453125, 3.248529672622680664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+66, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -10.7534723281860351, 1933.4913330078125, 34.68233871459960937, 1.473184108734130859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+67, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -60.6527786254882812, 1997.4478759765625, 33.65293121337890625, 3.020150423049926757, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+68, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -75.2847213745117187, 2005.079833984375, 33.58791351318359375, 4.985756874084472656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+69, 124382, 1643, 8721, 9032, '0', 0, 0, 0, 0, -6.48090267181396484, 1991.1353759765625, 38.97532272338867187, 3.490034341812133789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bonepicker Raven (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 248065 - Possessed)
(@CGUID+70, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -118.977432250976562, 1989.6336669921875, 33.4007568359375, 2.310781478881835937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+71, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -115.081596374511718, 1985.4166259765625, 33.5699462890625, 2.638638734817504882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+72, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -0.32465279102325439, 1969.9149169921875, 34.60957717895507812, 5.130801200866699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+73, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -20.1076393127441406, 1980.2708740234375, 33.99919891357421875, 4.643116950988769531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+74, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -62.4461822509765625, 1954.064208984375, 32.72285079956054687, 2.21019148826599121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+75, 124170, 1643, 8721, 9032, '0', 0, 0, 0, 0, -27.9600696563720703, 1956.4774169921875, 32.94057083129882812, 0.577671647071838378, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Fallhaven Pig (Area: Fallhaven - Difficulty: 0) CreateObject2 (Auras: 247043 - Possessed)
(@CGUID+76, 130194, 1643, 8721, 9032, '0', 0, 0, 0, 0, -88.6024322509765625, 1948.826416015625, 32.45882034301757812, 0.961605668067932128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Foulwater Rat (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+77, 129794, 1643, 8721, 9032, '0', 0, 0, 0, 0, -137.211807250976562, 2053.444580078125, 32.18792343139648437, 5.803989410400390625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Deep Woods Leaper (Area: Fallhaven - Difficulty: 0) CreateObject2
(@CGUID+78, 130483, 1643, 8721, 9032, '0', 0, 0, 0, 0, -94.953125, 2144.921875, 46.26339340209960937, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Pumpkin (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258273 - Pumpkin)
(@CGUID+79, 124173, 1643, 8721, 9032, '0', 0, 0, 0, 0, -26.9357643127441406, 2058.82470703125, 48.92804718017578125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Blightfly Swarm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+80, 130483, 1643, 8721, 9032, '0', 0, 0, 0, 0, -23.713541030883789, 2057.9375, 47.021575927734375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Pumpkin (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258273 - Pumpkin)
(@CGUID+81, 124173, 1643, 8721, 9032, '0', 0, 0, 0, 0, -38.8090286254882812, 2069.960205078125, 48.86457443237304687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Blightfly Swarm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+82, 130483, 1643, 8721, 9032, '0', 0, 0, 0, 0, -67.2864608764648437, 2004.2882080078125, 33.60050201416015625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Pumpkin (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258273 - Pumpkin)
(@CGUID+83, 130483, 1643, 8721, 9032, '0', 0, 0, 0, 0, -35.8802070617675781, 2054.3125, 47.02154159545898437, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Pumpkin (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258273 - Pumpkin)
(@CGUID+84, 124173, 1643, 8721, 9032, '0', 0, 0, 0, 0, -106.131942749023437, 2265.8056640625, 48.46220016479492187, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Blightfly Swarm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+85, 124173, 1643, 8721, 9032, '0', 0, 0, 0, 0, -89.2916641235351562, 2269.489501953125, 48.44842529296875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Blightfly Swarm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+86, 130483, 1643, 8721, 9032, '0', 0, 0, 0, 0, -82.8628463745117187, 2242.736083984375, 46.67516708374023437, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Pumpkin (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258273 - Pumpkin)
(@CGUID+87, 124173, 1643, 8721, 9032, '0', 0, 0, 0, 0, -139.880203247070312, 2278.517333984375, 50.89167022705078125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Blightfly Swarm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+88, 124173, 1643, 8721, 9032, '0', 0, 0, 0, 0, -104.152778625488281, 2296.005126953125, 48.408050537109375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Blightfly Swarm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+89, 130483, 1643, 8721, 9032, '0', 0, 0, 0, 0, -81.203125, 2294.791748046875, 46.23389434814453125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888); -- Pumpkin (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258273 - Pumpkin)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+89;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248065'), -- Bonepicker Raven - 248065 - Possessed
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248065'), -- Bonepicker Raven - 248065 - Possessed
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248065'), -- Bonepicker Raven - 248065 - Possessed
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248065'); -- Bonepicker Raven - 248065 - Possessed

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (124382,124548,124173,130483);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(124382, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '248065'), -- 124382 (Bonepicker Raven) - Possessed
(124548, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '247395'), -- 124548 (Betsy) - Possessed
(124173, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 124173 (Blightfly Swarm)
(130483, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '258273'); -- 130483 (Pumpkin) - Pumpkin

-- Template
UPDATE `creature_template` SET `unit_flags3`=0x14000000 WHERE `entry`=124548; -- Betsy
UPDATE `creature_template` SET `unit_flags3`=0x4000000 WHERE `entry`=124170; -- Fallhaven Pig
UPDATE `creature_template` SET `unit_flags3`=0x4000000 WHERE `entry`=124382; -- Bonepicker Raven
UPDATE `creature_template` SET `unit_flags3`=0x41000000 WHERE `entry`=124173; -- Blightfly Swarm
UPDATE `creature_template` SET `unit_flags`=0x0 WHERE `entry`=129794; -- Deep Woods Leaper
UPDATE `creature_template` SET `unit_flags3`=0x1000001 WHERE `entry`=130483; -- Pumpkin

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=124548 AND `DifficultyID`=0); -- 124548 (Betsy) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=59888 WHERE (`Entry`=124173 AND `DifficultyID`=0); -- 124173 (Blightfly Swarm) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=124170 AND `DifficultyID`=0); -- 124170 (Fallhaven Pig) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=59888 WHERE (`Entry`=124382 AND `DifficultyID`=0); -- 124382 (Bonepicker Raven) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=129794 AND `DifficultyID`=0); -- 129794 (Deep Woods Leaper) - CanSwim

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=59888 WHERE `DisplayID` IN (78048, 64016, 70451, 71224, 70663, 70449, 45494, 80919, 70443, 80953, 8014, 78051, 78052);
UPDATE `creature_model_info` SET `BoundingRadius`=2.658849954605102539, `CombatReach`=3.20000004768371582, `VerifiedBuild`=59888 WHERE `DisplayID`=81078;
UPDATE `creature_model_info` SET `BoundingRadius`=1.847484946250915527, `VerifiedBuild`=59888 WHERE `DisplayID`=80962;

-- Bonepicker Raven smart ai
SET @ENTRY := 124382;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 258247, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 258247 on self', '');

UPDATE `creature` SET `StringId` = 'ChannelPerched' WHERE `guid` IN (@CGUID+63, @CGUID+18, @CGUID+17, @CGUID+24, @CGUID+26, @CGUID+27, @CGUID+34, @CGUID+47, @CGUID+42, @CGUID+35);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 124382 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 124382, 0, 0, 58, 1, 0, 0, 0, 'ChannelPerched', 0, 'Object has StringID ChannelPerched');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 124382;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -60.455692, 2095.537, 56.987743, NULL, 0),
(@PATH, 1, -51.143124, 2088.8232, 56.987743, NULL, 0),
(@PATH, 2, -49.305664, 2077.4907, 56.987743, NULL, 0),
(@PATH, 3, -56.01968, 2068.178, 56.987743, NULL, 0),
(@PATH, 4, -67.35219, 2066.3406, 56.987743, NULL, 0),
(@PATH, 5, -76.66476, 2073.0547, 56.987743, NULL, 0),
(@PATH, 6, -78.50221, 2084.3872, 56.987743, NULL, 0),
(@PATH, 7, -71.7882, 2093.6997, 56.987743, NULL, 0),
(@PATH, 8, -60.455692, 2095.537, 56.987743, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+16;
SET @ENTRY := 124382;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -79.64028, 2039.8218, 51.672264, NULL, 0),
(@PATH, 1, -75.140045, 2029.26, 51.672264, NULL, 0),
(@PATH, 2, -64.48964, 2024.9739, 51.672264, NULL, 0),
(@PATH, 3, -53.92793, 2029.4741, 51.672264, NULL, 0),
(@PATH, 4, -49.64181, 2040.1245, 51.672264, NULL, 0),
(@PATH, 5, -54.142036, 2050.6863, 51.672264, NULL, 0),
(@PATH, 6, -64.79244, 2054.9724, 51.672264, NULL, 0),
(@PATH, 7, -75.354164, 2050.4722, 51.672264, NULL, 0),
(@PATH, 8, -79.64028, 2039.8218, 51.672264, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+21;
SET @ENTRY := 124382;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -65.885056, 2112.79, 63.74511, NULL, 0),
(@PATH, 1, -61.8925, 2102.0261, 63.74511, NULL, 0),
(@PATH, 2, -66.680565, 2091.5918, 63.74511, NULL, 0),
(@PATH, 3, -77.44446, 2087.599, 63.74511, NULL, 0),
(@PATH, 4, -87.878845, 2092.3872, 63.74511, NULL, 0),
(@PATH, 5, -91.8714, 2103.1511, 63.74511, NULL, 0),
(@PATH, 6, -87.08334, 2113.5854, 63.74511, NULL, 0),
(@PATH, 7, -76.31944, 2117.5781, 63.74511, NULL, 0),
(@PATH, 8, -65.885056, 2112.79, 63.74511, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+25;
SET @ENTRY := 124382;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8682, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -100.7569, 2211.9897, 51.361908, NULL, 0),
(@PATH, 1, -91.499466, 2205.2, 51.361908, NULL, 0),
(@PATH, 2, -80.15233, 2206.9448, 51.361908, NULL, 0),
(@PATH, 3, -73.36249, 2216.2021, 51.361908, NULL, 0),
(@PATH, 4, -75.10733, 2227.5493, 51.361908, NULL, 0),
(@PATH, 5, -84.36476, 2234.339, 51.361908, NULL, 0),
(@PATH, 6, -95.71189, 2232.5942, 51.361908, NULL, 0),
(@PATH, 7, -102.50174, 2223.337, 51.361908, NULL, 0),
(@PATH, 8, -100.7569, 2211.9897, 51.361908, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+29;
SET @ENTRY := 124382;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8682, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -145.09598, 2242.7056, 56.0904, NULL, 0),
(@PATH, 1, -155.93173, 2238.9124, 56.0904, NULL, 0),
(@PATH, 2, -160.91154, 2228.568, 56.0904, NULL, 0),
(@PATH, 3, -157.11832, 2217.7324, 56.0904, NULL, 0),
(@PATH, 4, -146.77408, 2212.7527, 56.0904, NULL, 0),
(@PATH, 5, -135.93834, 2216.546, 56.0904, NULL, 0),
(@PATH, 6, -130.95851, 2226.8901, 56.0904, NULL, 0),
(@PATH, 7, -134.75172, 2237.7258, 56.0904, NULL, 0),
(@PATH, 8, -145.09598, 2242.7056, 56.0904, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+31;
SET @ENTRY := 124382;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -64.91662, 2136.8918, 63.033394, NULL, 0),
(@PATH, 1, -62.205093, 2125.736, 63.033394, NULL, 0),
(@PATH, 2, -68.17602, 2115.9307, 63.033394, NULL, 0),
(@PATH, 3, -79.33171, 2113.219, 63.033394, NULL, 0),
(@PATH, 4, -89.13732, 2119.19, 63.033394, NULL, 0),
(@PATH, 5, -91.848854, 2130.3457, 63.033394, NULL, 0),
(@PATH, 6, -85.87792, 2140.1514, 63.033394, NULL, 0),
(@PATH, 7, -74.72222, 2142.8628, 63.033394, NULL, 0),
(@PATH, 8, -64.91662, 2136.8918, 63.033394, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 124382;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -85.57428, 2287.2463, 52.076546, NULL, 0),
(@PATH, 1, -74.84589, 2291.3335, 52.076546, NULL, 0),
(@PATH, 2, -70.14972, 2301.8096, 52.076546, NULL, 0),
(@PATH, 3, -74.23672, 2312.5378, 52.076546, NULL, 0),
(@PATH, 4, -84.712776, 2317.2341, 52.076546, NULL, 0),
(@PATH, 5, -95.44117, 2313.147, 52.076546, NULL, 0),
(@PATH, 6, -100.137344, 2302.671, 52.076546, NULL, 0),
(@PATH, 7, -96.05035, 2291.9426, 52.076546, NULL, 0),
(@PATH, 8, -85.57428, 2287.2463, 52.076546, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+40;
SET @ENTRY := 124382;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -112.7056, 2286.2383, 68.97972, NULL, 0),
(@PATH, 1, -101.519806, 2283.6536, 68.97972, NULL, 0),
(@PATH, 2, -95.43781, 2273.9165, 68.97972, NULL, 0),
(@PATH, 3, -98.02237, 2262.7307, 68.97972, NULL, 0),
(@PATH, 4, -107.75948, 2256.6487, 68.97972, NULL, 0),
(@PATH, 5, -118.94528, 2259.2334, 68.97972, NULL, 0),
(@PATH, 6, -125.02727, 2268.9705, 68.97972, NULL, 0),
(@PATH, 7, -122.44271, 2280.1562, 68.97972, NULL, 0),
(@PATH, 8, -112.7056, 2286.2383, 68.97972, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+43;
SET @ENTRY := 124382;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -108.4936, 2309.1914, 73.63837, NULL, 0),
(@PATH, 1, -104.025276, 2319.7666, 73.63837, NULL, 0),
(@PATH, 2, -93.387856, 2324.085, 73.63837, NULL, 0),
(@PATH, 3, -82.8126, 2319.6165, 73.63837, NULL, 0),
(@PATH, 4, -78.494354, 2308.9792, 73.63837, NULL, 0),
(@PATH, 5, -82.96268, 2298.4038, 73.63837, NULL, 0),
(@PATH, 6, -93.6001, 2294.0857, 73.63837, NULL, 0),
(@PATH, 7, -104.175354, 2298.554, 73.63837, NULL, 0),
(@PATH, 8, -108.4936, 2309.1914, 73.63837, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 124382;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8682, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -65.01233, 2270.364, 51.773674, NULL, 0),
(@PATH, 1, -69.99214, 2260.0198, 51.773674, NULL, 0),
(@PATH, 2, -80.82788, 2256.2266, 51.773674, NULL, 0),
(@PATH, 3, -91.172134, 2261.2063, 51.773674, NULL, 0),
(@PATH, 4, -94.96536, 2272.042, 51.773674, NULL, 0),
(@PATH, 5, -89.98555, 2282.3862, 51.773674, NULL, 0),
(@PATH, 6, -79.14981, 2286.1794, 51.773674, NULL, 0),
(@PATH, 7, -68.80556, 2281.1997, 51.773674, NULL, 0),
(@PATH, 8, -65.01233, 2270.364, 51.773674, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 124382;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -90.67469, 2278.5745, 73.80377, NULL, 0),
(@PATH, 1, -99.71792, 2285.6472, 73.80377, NULL, 0),
(@PATH, 2, -111.11355, 2284.2537, 73.80377, NULL, 0),
(@PATH, 3, -118.18616, 2275.2104, 73.80377, NULL, 0),
(@PATH, 4, -116.792725, 2263.815, 73.80377, NULL, 0),
(@PATH, 5, -107.74949, 2256.7422, 73.80377, NULL, 0),
(@PATH, 6, -96.35387, 2258.1357, 73.80377, NULL, 0),
(@PATH, 7, -89.28125, 2267.179, 73.80377, NULL, 0),
(@PATH, 8, -90.67469, 2278.5745, 73.80377, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');

-- Path for Bonepicker Raven
SET @MOVERGUID := @CGUID+48;
SET @ENTRY := 124382;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Bonepicker Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -107.33688, 2244.8352, 72.22231, NULL, 0),
(@PATH, 1, -97.63274, 2250.9697, 72.22231, NULL, 0),
(@PATH, 2, -95.10859, 2262.1692, 72.22231, NULL, 0),
(@PATH, 3, -101.24304, 2271.8733, 72.22231, NULL, 0),
(@PATH, 4, -112.44263, 2274.3975, 72.22231, NULL, 0),
(@PATH, 5, -122.146774, 2268.2632, 72.22231, NULL, 0),
(@PATH, 6, -124.67092, 2257.0635, 72.22231, NULL, 0),
(@PATH, 7, -118.53647, 2247.3594, 72.22231, NULL, 0),
(@PATH, 8, -107.33688, 2244.8352, 72.22231, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248065');
