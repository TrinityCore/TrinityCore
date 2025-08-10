SET @CGUID := 10003494;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+222;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2291.348876953125, -1223.52783203125, -1171.0640869140625, 5.126494884490966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+1, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2302.0712890625, -1229.84375, -1171.0665283203125, 5.126494884490966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+2, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2288.069580078125, -1214.26220703125, -1172.0152587890625, 4.975877761840820312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+4, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2311.588623046875, -1228.1458740234375, -1172.0152587890625, 5.255929470062255859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+3, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2290.755126953125, -1206.138916015625, -1172.0101318359375, 4.333794593811035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+5, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2285.052001953125, -1203.55908203125, -1171.904052734375, 4.522092819213867187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+6, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2340.8525390625, -1230.5572509765625, -1172.0390625, 0.016987772658467292, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+7, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2295.572998046875, -1202.439208984375, -1172.002197265625, 4.171202659606933593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+8, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2347.171875, -1236.310791015625, -1172.021728515625, 0.007706122938543558, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+9, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2338.911376953125, -1221.5850830078125, -1172.021728515625, 5.901524543762207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+10, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2342.29345703125, -1213.921875, -1172.021728515625, 5.80866098403930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+11, 224731, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2297.9462890625, -1225.1285400390625, -1171.075927734375, 5.254116058349609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Web Marauder (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+12, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2312.65966796875, -1181.267333984375, -1172.010009765625, 4.859982013702392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+13, 210932, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2384.7744140625, -1174.5572509765625, -1154.62890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+14, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2323.447998046875, -1186.5816650390625, -1172.01318359375, 5.279741764068603515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+15, 224731, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2344.8212890625, -1225.4149169921875, -1172.021728515625, 6.024016857147216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Web Marauder (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+16, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2341.9619140625, -1169.0850830078125, -1172.021728515625, 3.844301223754882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+17, 223181, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2349.89404296875, -1230.1822509765625, -1172.021728515625, 6.092586040496826171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Agile Pursuer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+18, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2347.973876953125, -1184.2847900390625, -1172.021728515625, 1.913787484169006347, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+19, 228361, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2288.56591796875, -1197.236083984375, -1171.984619140625, 4.622669696807861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Agile Pursuer (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+20, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2342.33154296875, -1181.04345703125, -1172.021728515625, 2.48097538948059082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+21, 223181, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2346.51904296875, -1218.5572509765625, -1172.021728515625, 5.96462869644165039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Agile Pursuer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+22, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2347.24658203125, -1166.3853759765625, -1172.021728515625, 4.01941680908203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+23, 224732, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2318.8125, -1181.546875, -1172.01318359375, 4.937350273132324218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Covert Webmancer (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+24, 220730, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2439.241455078125, -1175.1336669921875, -1138.6898193359375, 6.250831127166748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Venomshell (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+25, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2394.80029296875, -1190.4444580078125, -1152.80712890625, 5.992427825927734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+26, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2381.8994140625, -1159.8680419921875, -1154.62890625, 1.002214670181274414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+27, 228361, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2346.08154296875, -1174.592041015625, -1172.021728515625, 3.161014318466186523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Agile Pursuer (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+28, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2399.8212890625, -1179.6614990234375, -1150.322998046875, 5.714416980743408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+29, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2398.895751953125, -1193.0972900390625, -1150.4959716796875, 0.044801827520132064, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+30, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2396.54345703125, -1183.935791015625, -1152.6375732421875, 5.707517623901367187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+31, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2387.96875, -1159.4739990234375, -1154.1517333984375, 0.687418878078460693, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+32, 224732, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2311.916259765625, -1154.96142578125, -1171.971435546875, 5.915867805480957031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Covert Webmancer (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+33, 224731, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2310.300048828125, -1159.8448486328125, -1171.917724609375, 5.917921066284179687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Web Marauder (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+34, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2384.625, -1154.0191650390625, -1154.62890625, 0.523869335651397705, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+35, 224732, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2352.126708984375, -1174.970458984375, -1172.021728515625, 6.206318855285644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Covert Webmancer (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+36, 224732, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2295.84326171875, -1141.84130859375, -1172.021484375, 5.827226638793945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Covert Webmancer (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+37, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2392.692626953125, -1152.6163330078125, -1154.2022705078125, 0.331340909004211425, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+38, 228361, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2301.1572265625, -1143.6903076171875, -1172.021484375, 5.825423717498779296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Agile Pursuer (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 224731, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2401.223876953125, -1187.048583984375, -1150.166259765625, 6.004984855651855468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Web Marauder (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+40, 224732, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2405.1962890625, -1192.5, -1148.03515625, 6.02574920654296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Covert Webmancer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+41, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2509.007080078125, -1211.9478759765625, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+42, 210932, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2508.6875, -1193.02783203125, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+43, 224732, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2406.8212890625, -1180.079833984375, -1148.0343017578125, 5.721958637237548828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Covert Webmancer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+44, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2373.666748046875, -1091.4913330078125, -1172.021728515625, 2.356322765350341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+45, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2380.682373046875, -1094.4461669921875, -1172.021728515625, 1.391890525817871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+46, 210932, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2525.552001953125, -1215.1129150390625, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+47, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2537.93408203125, -1203.861083984375, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+48, 223357, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2371.9150390625, -1084.55908203125, -1172.021728515625, 3.25195932388305664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Conscript (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+49, 210933, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2526.135498046875, -1216.404541015625, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+50, 220196, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2381.03466796875, -1085.1978759765625, -1172.021728515625, 5.631479740142822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Herald of Ansurek (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+51, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2525.232666015625, -1233.6041259765625, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+52, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2543.114501953125, -1247.6666259765625, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+53, 210932, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2548.342041015625, -1235.27783203125, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+54, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2554.078125, -1220.1875, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+55, 216328, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2531.06591796875, -1134.2396240234375, -1132.035400390625, 6.042779445648193359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Unstable Test Subject (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 445862 - [DNT]Stomp Barrage, 18950 - Invisibility and Stealth Detection)
(@CGUID+56, 210933, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2561.97216796875, -1247.6007080078125, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+57, 216320, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2582.80029296875, -1175.15283203125, -1144.1280517578125, 1.595008134841918945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- The Coaglamation (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455154 - [DNT]Energize Purple, 443055 - [DNT] Invisible, 422362 - Bot AI Follow Advert)
(@CGUID+58, 216339, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2535.1875, -1214.265625, -1132.035400390625, 1.342490434646606445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+59, 216339, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2536.421875, -1232.767333984375, -1132.0352783203125, 6.138562679290771484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+60, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2504.61279296875, -1208.920166015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+61, 216328, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2572.28125, -1250.017333984375, -1132.035400390625, 0.387921363115310668, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Unstable Test Subject (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 445862 - [DNT]Stomp Barrage, 18950 - Invisibility and Stealth Detection)
(@CGUID+62, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2507.447998046875, -1205.3697509765625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+63, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2503.88720703125, -1143.5052490234375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+64, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2509.291748046875, -1208.795166015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+65, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2512.4306640625, -1210.9722900390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+66, 216339, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2540.411376953125, -1115.6180419921875, -1132.035400390625, 1.651041030883789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+67, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2507.92529296875, -1139.673583984375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+68, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2507.89404296875, -1143.111083984375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+69, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2513.654541015625, -1216.0035400390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+70, 216342, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2520.515625, -1143.1007080078125, -1132.0352783203125, 2.215559244155883789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+71, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2512.6337890625, -1135.4583740234375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+72, 216339, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2548.58251953125, -1112.0457763671875, -1132.021484375, 5.573016166687011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2523.703125, -1227.001708984375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+74, 221003, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2525.0556640625, -1175.017333984375, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+75, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2521.625, -1230.4791259765625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+76, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2516.3125, -1133.9722900390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+77, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2527.5087890625, -1151.5972900390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+78, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2530.757080078125, -1204.2083740234375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+79, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2530.06591796875, -1208.7396240234375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+80, 216342, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2519.564208984375, -1133.9132080078125, -1132.0352783203125, 3.299592018127441406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+81, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2534.73095703125, -1209.671875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+82, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2535.407958984375, -1205.0816650390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+83, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2527.572998046875, -1231.171875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+84, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2528.223876953125, -1227.1614990234375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+85, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2601.486083984375, -1260.5052490234375, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+86, 210933, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2600.42529296875, -1251.1910400390625, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+87, 216342, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2528.939208984375, -1146.0191650390625, -1132.0352783203125, 2.001423597335815429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+88, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2539.701416015625, -1207.73095703125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+89, 216339, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2555.717041015625, -1106.310791015625, -1132.0352783203125, 1.032439947128295898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+90, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2599.45654296875, -1236.859375, -1130.117431640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+91, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2531.765625, -1228.7100830078125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+92, 214542, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2613.0400390625, -1257.423583984375, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+93, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2519.75, -1120.4930419921875, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+94, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2529.78125, -1235.84375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+95, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2535.09375, -1148.701416015625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+96, 210933, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2616.9462890625, -1237.0069580078125, -1132.035400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+97, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2527.58154296875, -1119.220458984375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+98, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2543.37158203125, -1210.513916015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+99, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2524.5556640625, -1116.6788330078125, -1131.857421875, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+100, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2528.59375, -1112.8472900390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+101, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2528.5625, -1116.2847900390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+102, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2535.935791015625, -1113.4600830078125, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+103, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2545.885498046875, -1218.859375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+104, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2545.9306640625, -1135.859375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+105, 218374, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2558.53466796875, -1179.0572509765625, -1144.346435546875, 4.262948513031005859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Slime Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+106, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2547.829833984375, -1222.517333984375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+107, 218374, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2556.822998046875, -1174.5538330078125, -1144.0966796875, 3.144111871719360351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Slime Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+108, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2540.0556640625, -1241.3802490234375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+109, 216329, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2566.132080078125, -1169.5382080078125, -1144.1429443359375, 6.091007232666015625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+110, 216328, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2638.361083984375, -1220.982666015625, -1132.035400390625, 0.663895666599273681, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Unstable Test Subject (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 443339 - [DNT]Trash RP Sleep, 18950 - Invisibility and Stealth Detection)
(@CGUID+111, 218374, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2560.973876953125, -1168.798583984375, -1142.9833984375, 2.304230451583862304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Slime Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+112, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2552.00341796875, -1220.720458984375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+113, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2544.298583984375, -1111.642333984375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+114, 216339, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2575.64404296875, -1090.6458740234375, -1132.035400390625, 2.034100055694580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+115, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2540.2431640625, -1110.951416015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+116, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2549.342041015625, -1227.8125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+117, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2555.375, -1127.9149169921875, -1131.9071044921875, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+118, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2553.5087890625, -1225.9739990234375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+119, 216329, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2565.286376953125, -1185.93408203125, -1144.0848388671875, 4.029409408569335937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+120, 218067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2539.75341796875, -1104.9947509765625, -1131.631103515625, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+121, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2570.334228515625, -1178.1478271484375, -1144.224609375, 3.202081918716430664, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+122, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2555.52783203125, -1124.9722900390625, -1131.801025390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+123, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2543.194580078125, -1243.5572509765625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+124, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2569.86181640625, -1186.84521484375, -1144.0653076171875, 1.613013386726379394, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+125, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2544.882080078125, -1106.4132080078125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+126, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2567.40185546875, -1177.68212890625, -1144.22412109375, 1.038893699645996093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+127, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2547.81591796875, -1099.3367919921875, -1131.708984375, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+128, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2548.928955078125, -1107.123291015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+129, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2548.3525390625, -1250.8125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+130, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2551.71875, -1102.720458984375, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+131, 216339, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2590.029541015625, -1089.6458740234375, -1132.0352783203125, 1.068020224571228027, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+132, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2556.517333984375, -1244.4288330078125, -1132.0352783203125, 3.582104444503784179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+133, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2559.795166015625, -1114.1961669921875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+134, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2548.411376953125, -1245.16845703125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+135, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2559.920166015625, -1117.9617919921875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+136, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2543.46875, -1251.6285400390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+137, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2557.61279296875, -1120.3646240234375, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+138, 221101, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2582.954833984375, -1174.9010009765625, -1154.9166259765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Stalker (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+139, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2567.314208984375, -1111.1285400390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+140, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2553.95654296875, -1096.8802490234375, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+141, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2563.345458984375, -1112.2847900390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+142, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2556.94091796875, -1099.10595703125, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+143, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2562.451416015625, -1239.3367919921875, -1132.0352783203125, 3.965586423873901367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+144, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2562.782958984375, -1095.0242919921875, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+145, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2595.12109375, -1188.862548828125, -1144.1431884765625, 4.430912971496582031, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+146, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2558.421875, -1093.2916259765625, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+147, 221102, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2671.361083984375, -1183.373291015625, -1132.0050048828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Elder Shadeweaver (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 444428 - Honored Citizen)
(@CGUID+148, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2592.31591796875, -1174.17138671875, -1144.0894775390625, 5.896765708923339843, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+149, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2599.36962890625, -1181.8756103515625, -1144.054443359375, 3.460547208786010742, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+150, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2595.601318359375, -1179.370361328125, -1144.119873046875, 3.21105051040649414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+151, 216329, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2600.2255859375, -1173.47314453125, -1144.224609375, 3.81210494041442871, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56819), -- Congealed Droplet (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+152, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2558.717041015625, -1253.828125, -1132.0352783203125, 2.825456142425537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+153, 216339, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2640.65966796875, -1124.9410400390625, -1132.211181640625, 2.135377168655395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+154, 218374, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2606.088623046875, -1179.204833984375, -1143.49658203125, 5.135504722595214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Slime Stalker (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+155, 221103, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2683.57470703125, -1166.46533203125, -1132.008544921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hulking Warshell (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 444428 - Honored Citizen)
(@CGUID+156, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2588.907958984375, -1111.3350830078125, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+157, 218374, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2610.772705078125, -1175.079833984375, -1144.0966796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Slime Stalker (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+158, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2588.076416015625, -1114.421875, -1131.166748046875, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+159, 216339, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2631.18408203125, -1116.5364990234375, -1132.035400390625, 2.685541152954101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Sureki Unnaturaler (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+160, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2567.2119140625, -1094.8541259765625, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+161, 218374, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2607.0869140625, -1170.8507080078125, -1143.49658203125, 0.800874292850494384, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Slime Stalker (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+162, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2571.86279296875, -1089.3160400390625, -1132.0352783203125, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+163, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2607.373291015625, -1117.1129150390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+164, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2587.359375, -1096.951416015625, -1132.035400390625, 4.670025825500488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+165, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2609.411376953125, -1119.2864990234375, -1132.035400390625, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+166, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2608.322998046875, -1126.564208984375, -1132.035400390625, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+167, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2608.33154296875, -1122.4617919921875, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+168, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2597.421875, -1110.4305419921875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+169, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2602.501708984375, -1110.623291015625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+170, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2604.48095703125, -1113.4774169921875, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+171, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2605.40283203125, -1122.0242919921875, -1132.035400390625, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+172, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2602.225830078125, -1238.0208740234375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+173, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2598.229248046875, -1240.15625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+174, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2631.1806640625, -1145.060791015625, -1132.000732421875, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+175, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2610.138916015625, -1115.939208984375, -1132.035400390625, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+176, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2618.616455078125, -1222.125, -1132.035400390625, 3.03151249885559082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+177, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2577.3125, -1083.2066650390625, -1131.4893798828125, 4.170844554901123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+178, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2619.20654296875, -1225.2413330078125, -1132.035400390625, 2.263981342315673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+179, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2603.388916015625, -1107.7413330078125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+180, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2630.307373046875, -1207.125, -1132.0352783203125, 2.545468091964721679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+181, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2624.54345703125, -1136.046875, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+182, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2621.1337890625, -1226.9305419921875, -1132.0352783203125, 2.448144435882568359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+183, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2599.272705078125, -1255.6353759765625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+184, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2608.013916015625, -1113.7135009765625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+185, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2623.192626953125, -1132.3367919921875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+186, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2628.842041015625, -1145.8316650390625, -1132.035400390625, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+187, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2622.161376953125, -1139.3038330078125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+188, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2606.6337890625, -1109.44970703125, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+189, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2625.560791015625, -1139.1163330078125, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+190, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2629.328125, -1136.2691650390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+191, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2628.07470703125, -1141.3038330078125, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+192, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2624.286376953125, -1209.392333984375, -1132.0352783203125, 2.545468091964721679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+193, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2630.979248046875, -1230.6978759765625, -1132.035400390625, 2.420596599578857421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+194, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2589.397705078125, -1083.1319580078125, -1131.4893798828125, 4.170844554901123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+195, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2631.7431640625, -1139.8489990234375, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+196, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2599.779541015625, -1091.0260009765625, -1132.035400390625, 4.170844554901123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+197, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2583.083251953125, -1079.96533203125, -1131.134765625, 4.053066253662109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+198, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2607.625, -1257.185791015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+199, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2611.755126953125, -1252.68408203125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+200, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2624.875, -1109.8992919921875, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+201, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2607.55029296875, -1252.3941650390625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+202, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2586.953125, -1081.982666015625, -1131.492431640625, 4.170844554901123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+203, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2583.609375, -1083.689208984375, -1131.4873046875, 4.053066253662109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+204, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2616.14404296875, -1253.0850830078125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+205, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2580.40966796875, -1082.1822509765625, -1131.2640380859375, 4.170844554901123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+206, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2638.93408203125, -1118.3541259765625, -1132.035400390625, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+207, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2617.763916015625, -1096.9722900390625, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+208, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2614.7900390625, -1095.671875, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+209, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2632.74658203125, -1240.953125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+210, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2609.177001953125, -1092.2882080078125, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+211, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2629.90283203125, -1106.720458984375, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+212, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2626.286376953125, -1105.015625, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+213, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2640.1337890625, -1114.6875, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+214, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2628.65625, -1111.795166015625, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+215, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2634.354248046875, -1107.486083984375, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+216, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2633.151123046875, -1110.7083740234375, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+217, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2627.638916015625, -1108.7257080078125, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+218, 216342, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2637.6181640625, -1231.154541015625, -1132.035400390625, 0.923772275447845458, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittering Assistant (Area: The Transformatory - Difficulty: Follower) CreateObject1
(@CGUID+219, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2635.6494140625, -1116.560791015625, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+220, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2612.32470703125, -1093.296875, -1132.035400390625, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+221, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2636.515625, -1239.19970703125, -1132.0352783203125, 3.503216981887817382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
(@CGUID+222, 218067, 2669, 14979, 15113, '1,2,8,23', 0, 0, 0, 0, -2636.255126953125, -1113.09375, -1132.0352783203125, 5.178589344024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819); -- Cocoon (Area: The Transformatory - Difficulty: Follower) CreateObject1 (Auras: 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+222;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+5, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+7, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+12, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+14, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Agile Pursuer
(@CGUID+20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Covert Webmancer
(@CGUID+26, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+31, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+34, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+37, 0, 0, 0, 0, 0, 0, 0, 375, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sureki Conscript
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+73, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+75, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+81, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+84, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+88, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+91, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+97, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+101, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+103, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+106, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+108, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+112, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+117, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+118, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+120, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+123, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+125, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+130, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+135, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+144, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+163, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+164, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+165, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+166, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+168, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+169, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+170, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+171, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+173, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+174, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+175, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+177, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+179, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+180, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+181, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+183, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+184, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+185, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+186, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+187, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+188, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+189, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+190, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+191, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+193, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Skittering Assistant
(@CGUID+194, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+195, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+196, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+197, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+198, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+199, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+200, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+201, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+202, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+203, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+204, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+205, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+206, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+207, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+208, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+209, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+210, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+211, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+212, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+213, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+214, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+215, 0, 0, 0, 0, 0, 1, 0, 0, 8608, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+216, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+217, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+218, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Skittering Assistant
(@CGUID+219, 0, 0, 0, 0, 0, 1, 0, 0, 3421, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+220, 0, 0, 0, 0, 0, 1, 0, 0, 30470, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+221, 0, 0, 0, 0, 0, 1, 0, 0, 3503, 0, 0, 0, '436330 443377'), -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon
(@CGUID+222, 0, 0, 0, 0, 0, 1, 0, 0, 30471, 0, 0, 0, '436330 443377'); -- Cocoon - 436330 - Detection Aura, 443377 - [DNT]Trash RP Cocoon

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (221103 /*221103 (Hulking Warshell) - Honored Citizen*/, 221102 /*221102 (Elder Shadeweaver) - Honored Citizen*/, 218374 /*218374 (Slime Stalker)*/, 218067 /*218067 (Cocoon) - Detection Aura, [DNT]Trash RP Cocoon*/, 216320 /*216320 (The Coaglamation) - [DNT]Energize Purple, [DNT] Invisible, Bot AI Follow Advert*/, 216328 /*216328 (Unstable Test Subject) - [DNT]Stomp Barrage, Invisibility and Stealth Detection*/, 223357 /*223357 (Sureki Conscript)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(221103, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '444428'), -- 221103 (Hulking Warshell) - Honored Citizen
(221102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '444428'), -- 221102 (Elder Shadeweaver) - Honored Citizen
(218374, 0, 0, 0, 0, 0, 1, 0, 0, 30472, 0, 0, 0, ''), -- 218374 (Slime Stalker)
(218067, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436330 443377'), -- 218067 (Cocoon) - Detection Aura, [DNT]Trash RP Cocoon
(216320, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455154 443055 422362'), -- 216320 (The Coaglamation) - [DNT]Energize Purple, [DNT] Invisible, Bot AI Follow Advert
(216328, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '445862 18950'), -- 216328 (Unstable Test Subject) - [DNT]Stomp Barrage, Invisibility and Stealth Detection
(223357, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 223357 (Sureki Conscript)

-- Template
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=221103; -- Hulking Warshell
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=221102; -- Elder Shadeweaver
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1073741825, `flags_extra` = 128 WHERE `entry`=221101; -- Stalker
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216329; -- Congealed Droplet
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1073741824, `flags_extra` = 128 WHERE `entry`=218374; -- Slime Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=216342; -- Skittering Assistant
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=2048, `unit_flags3`=1090519041 WHERE `entry`=218067; -- Cocoon
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=216339; -- Sureki Unnaturaler
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33555264 WHERE `entry`=216320; -- The Coaglamation
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=216328; -- Unstable Test Subject
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=214542; -- Path Helper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220730; -- Royal Venomshell
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=224732; -- Covert Webmancer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry` IN (228361, 223181); -- Agile Pursuer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=224731; -- Web Marauder
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=223357; -- Sureki Conscript

-- Path for Web Marauder
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+33;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+33, @CGUID+33, 0, 0, 515, 3, 14),
(@CGUID+33, @CGUID+32, 4, 270, 515, 3, 14);

SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 224731;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Web Marauder - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2301.1396, -1163.3099, -1172.0198, NULL, 0),
(@PATH, 1, -2297.955, -1164.5045, -1171.9027, NULL, 0),
(@PATH, 2, -2294.889, -1165.6547, -1171.8856, NULL, 0),
(@PATH, 3, -2292.9395, -1166.3859, -1171.8997, NULL, 4140),
(@PATH, 4, -2296.4595, -1165.0656, -1171.8743, NULL, 0),
(@PATH, 5, -2299.5552, -1163.9043, -1171.9615, NULL, 0),
(@PATH, 6, -2302.6436, -1162.746, -1172.137, NULL, 0),
(@PATH, 7, -2305.4473, -1161.6942, -1172.0048, NULL, 0),
(@PATH, 8, -2307.9666, -1160.7491, -1172.2246, NULL, 0),
(@PATH, 9, -2310.7058, -1159.7124, -1171.8207, NULL, 0),
(@PATH, 10, -2313.5483, -1158.6191, -1172.1315, NULL, 0),
(@PATH, 11, -2316.3867, -1157.5272, -1172.0796, NULL, 0),
(@PATH, 12, -2319.2153, -1156.4391, -1172.0277, NULL, 0),
(@PATH, 13, -2322.0469, -1155.3497, -1171.8446, NULL, 0),
(@PATH, 14, -2324.6914, -1154.3323, -1171.9563, NULL, 4053),
(@PATH, 15, -2320.8901, -1155.7947, -1171.8245, NULL, 0),
(@PATH, 16, -2318.034, -1156.8936, -1172.0493, NULL, 0),
(@PATH, 17, -2315.1936, -1157.9863, -1172.1014, NULL, 0),
(@PATH, 18, -2312.3699, -1159.0726, -1172.0887, NULL, 0),
(@PATH, 19, -2309.3267, -1160.2385, -1172.222, NULL, 0),
(@PATH, 20, -2306.2266, -1161.402, -1172.2246, NULL, 0),
(@PATH, 21, -2304.1619, -1162.1763, -1171.8756, NULL, 0);

UPDATE `creature` SET `position_x`=-2301.1396, `position_y`=-1163.3099, `position_z`=-1172.0198, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Agile Pursuer
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+38;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+38, @CGUID+38, 0, 0, 515, 1, 13),
(@CGUID+38, @CGUID+36, 4, 270, 515, 1, 13);

SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 228361;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Agile Pursuer - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2292.9905, -1147.6956, -1172.0215, NULL, 0),
(@PATH, 1, -2291.5496, -1148.4021, -1172.0215, NULL, 3562),
(@PATH, 2, -2295.2524, -1146.586, -1172.0215, NULL, 0),
(@PATH, 3, -2297.984, -1145.2466, -1172.0215, NULL, 0),
(@PATH, 4, -2300.6992, -1143.9148, -1172.0215, NULL, 0),
(@PATH, 5, -2303.4329, -1142.5742, -1172.0215, NULL, 0),
(@PATH, 6, -2306.1636, -1141.2313, -1171.992, NULL, 0),
(@PATH, 7, -2308.8994, -1139.8818, -1171.9474, NULL, 0),
(@PATH, 8, -2311.634, -1138.5331, -1171.9622, NULL, 0),
(@PATH, 9, -2314.3416, -1137.1976, -1171.9767, NULL, 0),
(@PATH, 10, -2317.0876, -1135.8434, -1171.9913, NULL, 0),
(@PATH, 11, -2319.8042, -1134.5034, -1172.006, NULL, 0),
(@PATH, 12, -2322.5254, -1133.1613, -1172.0215, NULL, 0),
(@PATH, 13, -2323.386, -1132.7367, -1172.0215, NULL, 3226),
(@PATH, 14, -2319.6877, -1134.5608, -1172.0054, NULL, 0),
(@PATH, 15, -2316.9578, -1135.9073, -1171.9907, NULL, 0),
(@PATH, 16, -2314.2366, -1137.2494, -1171.9761, NULL, 0),
(@PATH, 17, -2311.5156, -1138.5916, -1171.9614, NULL, 0),
(@PATH, 18, -2308.8015, -1139.9303, -1171.9469, NULL, 0),
(@PATH, 19, -2306.0718, -1141.2767, -1171.9943, NULL, 0),
(@PATH, 20, -2303.3518, -1142.614, -1172.0215, NULL, 0),
(@PATH, 21, -2300.6228, -1143.9524, -1172.0215, NULL, 0),
(@PATH, 22, -2297.8894, -1145.2928, -1172.0215, NULL, 0),
(@PATH, 23, -2295.1538, -1146.6345, -1172.0215, NULL, 0);

UPDATE `creature` SET `position_x`=-2292.9905, `position_y`=-1147.6956, `position_z`=-1172.0215, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Sureki Unnaturaler
SET @MOVERGUID := @CGUID+72;
SET @ENTRY := 216339;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Sureki Unnaturaler - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2569.0312, -1094.4635, -1132.0215, NULL, 0),
(@PATH, 1, -2615.823, -1098.4548, -1132.0215, NULL, 9802),
(@PATH, 2, -2618.3315, -1111.5695, -1132.0488, NULL, 5881),
(@PATH, 3, -2615.823, -1098.4548, -1132.0215, NULL, 0),
(@PATH, 4, -2569.0312, -1094.4635, -1132.0215, NULL, 0),
(@PATH, 5, -2545.3386, -1114.8351, -1132.0027, NULL, 5895);

UPDATE `creature` SET `position_x`=-2569.0312, `position_y`=-1094.4635, `position_z`=-1132.0215, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
