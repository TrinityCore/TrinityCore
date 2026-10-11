SET @CGUID := 11000649;
SET @OGUID := 11000020;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+70;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1279.7396240234375, 864.38018798828125, 1328.6943359375, 4.665193080902099609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+1, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1301.15283203125, 856.60418701171875, 1330.354736328125, 0.766289472579956054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+2, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1328.2847900390625, 882.3507080078125, 1344.6680908203125, 4.665193080902099609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+3, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1333.2916259765625, 910.08856201171875, 1367.6905517578125, 5.441879749298095703, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1307.3680419921875, 915.310791015625, 1336.75, 4.521508216857910156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1262.9114990234375, 829.13018798828125, 1332.329345703125, 5.007440090179443359, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1289.545166015625, 896.28472900390625, 1335.830078125, 3.724887371063232421, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1266.26220703125, 832.94793701171875, 1332.7568359375, 5.518473148345947265, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+8, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1248.751708984375, 873.26910400390625, 1362.4405517578125, 4.632912635803222656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+9, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1297.984375, 874.84027099609375, 1331.7841796875, 6.014566898345947265, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+10, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1334.1197509765625, 893.171875, 1346.1248779296875, 0.325119495391845703, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+11, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1308.69970703125, 877.125, 1338.8040771484375, 0.833702564239501953, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1262.607666015625, 827.45660400390625, 1345.630615234375, 5.421803474426269531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1302.9913330078125, 903.9288330078125, 1351.1243896484375, 4.322881221771240234, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1272.1944580078125, 699.7430419921875, 1397.3477783203125, 4.817058563232421875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+15, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1225.23095703125, 753.3125, 1330.7554931640625, 2.222631454467773437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1234.967041015625, 734.185791015625, 1331.5206298828125, 5.430673599243164062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+17, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1278.907958984375, 769.22222900390625, 1330.619384765625, 3.994721651077270507, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+18, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1273.7066650390625, 729.19097900390625, 1331.4862060546875, 0.166934013366699218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+19, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1290.923583984375, 741.61285400390625, 1331.7236328125, 0.665167570114135742, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+20, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1284.34375, 768.34893798828125, 1330.0596923828125, 1.505312323570251464, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+21, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1325.0555419921875, 774.09375, 1333.641357421875, 0.633518517017364501, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+22, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1283.3992919921875, 796.732666015625, 1343.99072265625, 3.590230703353881835, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1271.4114990234375, 747.34722900390625, 1330.98095703125, 2.903629064559936523, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+24, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1264.470458984375, 717.98614501953125, 1333.0911865234375, 2.188169240951538085, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+25, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1285.8697509765625, 797.3663330078125, 1331.5302734375, 2.499593734741210937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (Auras: 1250486 - High-Value Beast) (possible waypoints or random movement)
(@CGUID+26, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1285.6649169921875, 801.8038330078125, 1331.852783203125, 2.094257593154907226, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 245114, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1126.8680419921875, 880.0867919921875, 1340.6632080078125, 2.467528581619262695, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Vicious Saptor (Area: Har'mara - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1205.7882080078125, 831.65802001953125, 1329.9727783203125, 4.245204448699951171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1212.1805419921875, 814.5850830078125, 1329.729248046875, 4.986347198486328125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1172.2535400390625, 814.28472900390625, 1350.0543212890625, 5.441879749298095703, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1197.65625, 803.11285400390625, 1353.4312744140625, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1149.16845703125, 880.263916015625, 1356.376708984375, 3.30220198631286621, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+33, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1185.49658203125, 806.092041015625, 1333.003662109375, 1.89648592472076416, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+34, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1189.1910400390625, 821.6007080078125, 1332.8319091796875, 4.606882572174072265, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+35, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1177.40625, 789.28472900390625, 1334.004150390625, 1.437374830245971679, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+36, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1215.73095703125, 826.45831298828125, 1329.8011474609375, 2.942288875579833984, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+37, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1191.3541259765625, 925.607666015625, 1330.4775390625, 2.475512027740478515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+38, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1238.6927490234375, 887.78472900390625, 1331.400634765625, 3.469159364700317382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+39, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1221.4774169921875, 927.09552001953125, 1331.4822998046875, 4.643042564392089843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+40, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1216.6978759765625, 941.53472900390625, 1332.35986328125, 0.970654547214508056, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+41, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1319.90625, 964.34893798828125, 1347.1171875, 4.486883163452148437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+42, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1201.4774169921875, 881.625, 1332.2554931640625, 1.596370697021484375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+43, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1225.90625, 927.2882080078125, 1333.0439453125, 1.841365933418273925, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+44, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1195.5660400390625, 900.3194580078125, 1344.765869140625, 6.024446010589599609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+45, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1201.0867919921875, 905.13714599609375, 1330.8714599609375, 3.840784311294555664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+46, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1194.3975830078125, 946.3211669921875, 1329.5537109375, 2.878571271896362304, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+47, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1231.4166259765625, 903.810791015625, 1332.3154296875, 0.852510750293731689, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+48, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1208.1441650390625, 925.69964599609375, 1337.216064453125, 0.2813262939453125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+49, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1228.90283203125, 988.87152099609375, 1330.49267578125, 4.795212268829345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+50, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1258.8524169921875, 1000.09197998046875, 1331.01220703125, 3.554572820663452148, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+51, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1217.763916015625, 979.109375, 1332.8763427734375, 3.234653949737548828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+52, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1144.0208740234375, 933.59375, 1343.85400390625, 1.751643657684326171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+53, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1252.201416015625, 992.75518798828125, 1331.3984375, 5.450029850006103515, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+54, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1143.8194580078125, 964.40277099609375, 1356.2708740234375, 5.025057315826416015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+55, 237036, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1170.91845703125, 961.76910400390625, 1341.1671142578125, 5.521956920623779296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Lashroom Bud (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+56, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1243.060791015625, 990.20831298828125, 1342.5679931640625, 3.945434808731079101, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+57, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1239.640625, 976.78125, 1332.416015625, 1.571391820907592773, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+58, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1267.1597900390625, 994.0538330078125, 1332.5791015625, 1.675621390342712402, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+59, 245117, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1346.4288330078125, 979.11285400390625, 1329.609619140625, 2.72369694709777832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Pesky Sludger (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+60, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1280.734375, 1009.00872802734375, 1328.994140625, 5.477174282073974609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+61, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1352.5260009765625, 1045.62158203125, 1370.0010986328125, 4.477639198303222656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+62, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1327.7239990234375, 987.23785400390625, 1328.9873046875, 5.599215030670166015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+63, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1349.73095703125, 1002.06768798828125, 1337.474609375, 3.653069019317626953, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+64, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1305.15283203125, 958.97918701171875, 1331.8116455078125, 0.645912647247314453, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+65, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1368.501708984375, 1017.44622802734375, 1339.3486328125, 0.223540291190147399, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+66, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1343.7882080078125, 1021.54522705078125, 1356.90087890625, 5.169723033905029296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+67, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1356.98095703125, 1040.0728759765625, 1343.625, 2.54312300682067871, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+68, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1309.1163330078125, 1025.8541259765625, 1333.4609375, 1.991940140724182128, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+69, 245118, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1331.5382080078125, 940.0867919921875, 1330.7901611328125, 4.955296039581298828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Invasive Drifter (Area: Har'mara - Difficulty: 0) CreateObject2
(@CGUID+70, 237068, 2694, 15355, 15928, '0', 26622, 0, 0, 0, 1319.90625, 964.34893798828125, 1347.1171875, 4.486883163452148437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 66838); -- Spore-Covered Firefly (Area: Har'mara - Difficulty: 0) CreateObject2

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 620076, 2694, 15355, 15928, '0', 26622, 0, 1352.9774169921875, 906.14410400390625, 1345.3524169921875, 1.325773000717163085, 0, 0, 0.61539459228515625, 0.788219213485717773, 120, 255, 1, 66838), -- Mailbox (Area: Har'mara - Difficulty: 0) CreateObject1
(@OGUID+1, 542334, 2694, 15355, 15928, '0', 26622, 0, 595.8211669921875, 227.6996612548828125, 1158.6407470703125, 0, 0, 0, 0, 1, 120, 255, 0, 66838), -- Ancient Visionstone (Area: Har'mara - Difficulty: 0) CreateObject1
(@OGUID+2, 546728, 2694, 15355, 15928, '0', 26622, 0, 1144.6805419921875, 1057.5086669921875, 1320.9173583984375, 4.8823699951171875, -0.06232452392578125, 0.07067108154296875, -0.64066886901855468, 0.762013554573059082, 120, 255, 1, 66838), -- Legacy Stone of True Calling (Area: Har'mara - Difficulty: 0) CreateObject1
(@OGUID+3, 554679, 2694, 15355, 15928, '0', 26622, 0, 1098.157958984375, 1033.798583984375, 1339.0015869140625, 6.276787281036376953, -0.00849342346191406, -0.00138568878173828, -0.00321102142333984, 0.999957799911499023, 120, 255, 1, 66838), -- Legacy Stone of True Self (Area: Har'mara - Difficulty: 0) CreateObject1
(@OGUID+4, 554848, 2694, 15355, 15928, '0', 26622, 0, 1142.3975830078125, 1130.05908203125, 1310.259521484375, 5.667225360870361328, 0.008546352386474609, -0.01894569396972656, -0.30286407470703125, 0.952807128429412841, 120, 255, 1, 66838), -- Legacy Stone of the Goddess Guidance (Area: Har'mara - Difficulty: 0) CreateObject1
(@OGUID+5, 554966, 2694, 15355, 15928, '0', 26622, 0, 1135.96533203125, 1167.0538330078125, 1310.147216796875, 6.215996265411376953, -0.03531312942504882, -0.16981887817382812, -0.03821086883544921, 0.984100878238677978, 120, 255, 1, 66838); -- Legacy Stone (Area: Har'mara - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (245118);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(245118, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 245118 (Invasive Drifter)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (554966 /*Legacy Stone*/, 554848 /*Legacy Stone of the Goddess Guidance*/, 554679 /*Legacy Stone of True Self*/, 546728 /*Legacy Stone of True Calling*/, 542334 /*Ancient Visionstone*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(554966, 0, 0x40000, 0, 0), -- Legacy Stone
(554848, 0, 0x40000, 0, 0), -- Legacy Stone of the Goddess Guidance
(554679, 0, 0x40000, 0, 0), -- Legacy Stone of True Self
(546728, 0, 0x40000, 0, 0), -- Legacy Stone of True Calling
(542334, 0, 0x20, 0, 0); -- Ancient Visionstone

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (554966 /*Legacy Stone*/, 554848 /*Legacy Stone of the Goddess Guidance*/, 554679 /*Legacy Stone of True Self*/, 546728 /*Legacy Stone of True Calling*/, 553763 /*Invasive Fungi*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(554966, 10, 105910, 'Legacy Stone', 'questinteract', '', '', 0.85000002384185791, 4163, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1242077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141651, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Legacy Stone
(554848, 10, 105910, 'Legacy Stone of the Goddess Guidance', 'questinteract', '', '', 0.85000002384185791, 4227, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1241353, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141586, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Legacy Stone of the Goddess Guidance
(554679, 10, 105910, 'Legacy Stone of True Self', 'questinteract', '', '', 0.85000002384185791, 4389, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1241222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141566, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Legacy Stone of True Self
(546728, 10, 105910, 'Legacy Stone of True Calling', 'questinteract', '', '', 0.800000011920928955, 4227, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1241295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141572, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Legacy Stone of True Calling
(553763, 10, 109980, 'Invasive Fungi', 'questinteract', '', '', 0.5, 4101, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838); -- Invasive Fungi

UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000 WHERE `entry`=248669; -- Withered Lasher
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1000000 WHERE `entry`=246474; -- Vision Summoned
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1000000 WHERE `entry`=246490; -- Vision of True Calling
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1000000 WHERE `entry`=246522; -- Vision of True Calling - Event
UPDATE `creature_template` SET `npcflag`=67108865, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=132969; -- Katy Stampwhistle
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x4000800, `unit_flags3`=0x8000 WHERE `entry`=248899; -- Har'mara Rotling
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248819; -- Zur'ashar Kassameh
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000 WHERE `entry`=246360; -- Outsider
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000 WHERE `entry`=247257; -- Help Outsider - Kill Credit
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=242650; -- Ney'leia
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248904; -- Har'mara Elder Root
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000 WHERE `entry`=253478; -- Seek Outsider
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=256045; -- Skyriding Glyph Tracker
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248818; -- Ku'paal
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=251883; -- Grove Protector Madar
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0xC1000000 WHERE `entry`=237725; -- Firefly
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248789; -- Hannan
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245114; -- Vicious Saptor
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248900; -- Har'mara Mycomancer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=249173; -- Har'alnorian Pilgrim
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248817; -- Ney'leia
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248901; -- Har'mara Grove Protector
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245090; -- Hagar
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248911; -- Har'kuaian Pilgrim
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000 WHERE `entry`=246284; -- Outsider's Gear
UPDATE `creature_template` SET `faction`=2299, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248905; -- Har'mara Grovewarden
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248910; -- Har'mara Citizen
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=237068; -- Spore-Covered Firefly
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x41000000 WHERE `entry`=246277; -- Withered Plant
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=245116; -- Tranquil Sporeglider
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245117; -- Pesky Sludger
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000 WHERE `entry`=246861; -- Faint Song
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=248902; -- Har'mara Blossomsinger
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=237036; -- Lashroom Bud
UPDATE `creature_template` SET `faction`=2299, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=248895; -- Har'mara Sporeguard
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245118; -- Invasive Drifter

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248669 AND `DifficultyID`=0); -- 248669 (Withered Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x20000000, `VerifiedBuild`=66838 WHERE (`Entry`=246474 AND `DifficultyID`=0); -- 246474 (Vision Summoned) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x20000000, `VerifiedBuild`=66838 WHERE (`Entry`=246490 AND `DifficultyID`=0); -- 246490 (Vision of True Calling) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x20000000, `VerifiedBuild`=66838 WHERE (`Entry`=246522 AND `DifficultyID`=0); -- 246522 (Vision of True Calling - Event) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248899 AND `DifficultyID`=0); -- 248899 (Har'mara Rotling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248819 AND `DifficultyID`=0); -- 248819 (Zur'ashar Kassameh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=246360 AND `DifficultyID`=0); -- 246360 (Outsider) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=247257 AND `DifficultyID`=0); -- 247257 (Help Outsider - Kill Credit) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=242650 AND `DifficultyID`=0); -- 242650 (Ney'leia) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248904 AND `DifficultyID`=0); -- 248904 (Har'mara Elder Root) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=253478 AND `DifficultyID`=0); -- 253478 (Seek Outsider) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3322, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=256045 AND `DifficultyID`=0); -- 256045 (Skyriding Glyph Tracker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248818 AND `DifficultyID`=0); -- 248818 (Ku'paal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=251883 AND `DifficultyID`=0); -- 251883 (Grove Protector Madar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=237725 AND `DifficultyID`=0); -- 237725 (Firefly) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248789 AND `DifficultyID`=0); -- 248789 (Hannan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245114 AND `DifficultyID`=0); -- 245114 (Vicious Saptor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248900 AND `DifficultyID`=0); -- 248900 (Har'mara Mycomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=249173 AND `DifficultyID`=0); -- 249173 (Har'alnorian Pilgrim) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248817 AND `DifficultyID`=0); -- 248817 (Ney'leia) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248901 AND `DifficultyID`=0); -- 248901 (Har'mara Grove Protector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245090 AND `DifficultyID`=0); -- 245090 (Hagar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248911 AND `DifficultyID`=0); -- 248911 (Har'kuaian Pilgrim) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=246284 AND `DifficultyID`=0); -- 246284 (Outsider's Gear) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248905 AND `DifficultyID`=0); -- 248905 (Har'mara Grovewarden) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248910 AND `DifficultyID`=0); -- 248910 (Har'mara Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=237068 AND `DifficultyID`=0); -- 237068 (Spore-Covered Firefly) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=246277 AND `DifficultyID`=0); -- 246277 (Withered Plant) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x30000000, `VerifiedBuild`=66838 WHERE (`Entry`=245116 AND `DifficultyID`=0); -- 245116 (Tranquil Sporeglider) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245117 AND `DifficultyID`=0); -- 245117 (Pesky Sludger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=246861 AND `DifficultyID`=0); -- 246861 (Faint Song) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248902 AND `DifficultyID`=0); -- 248902 (Har'mara Blossomsinger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=237036 AND `DifficultyID`=0); -- 237036 (Lashroom Bud) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=248895 AND `DifficultyID`=0); -- 248895 (Har'mara Sporeguard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x30000000, `VerifiedBuild`=66838 WHERE (`Entry`=245118 AND `DifficultyID`=0); -- 245118 (Invasive Drifter) - CanSwim, Floating

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (141183, 131738, 131736, 131735, 131740, 131818, 131820, 131737, 131734, 139907);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(141183, 0.5, 1, 0, 66838),
(131738, 0.580512702465057373, 1.5, 0, 66838),
(131736, 0.484952837228775024, 1.5, 0, 66838),
(131735, 0.484952837228775024, 1.5, 0, 66838),
(131740, 0.580512702465057373, 1.5, 0, 66838),
(131818, 0.580512702465057373, 1.5, 0, 66838),
(131820, 0.484952837228775024, 1.5, 0, 66838),
(131737, 0.580512702465057373, 1.5, 0, 66838),
(131734, 0.484952837228775024, 1.5, 0, 66838),
(139907, 0.25, 0.5, 0, 66838);

UPDATE `creature_model_info` SET `VerifiedBuild`=66838 WHERE `DisplayID` IN (118222, 127756, 118215, 126051, 118217, 115237, 137150, 118223, 118216, 27823, 138998, 115199, 137184, 23767, 118221, 140931, 131465, 115198, 127752, 112410, 115238, 114621, 137183, 122804, 127784, 126101, 129964, 125189, 118213);
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=66838 WHERE `DisplayID`=118214;
UPDATE `creature_model_info` SET `BoundingRadius`=0.441019505262374877, `VerifiedBuild`=66838 WHERE `DisplayID` IN (114623, 114622);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 26622;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(26622, 'Har''mara - Allied Race start hub');

DELETE FROM `phase_area` WHERE `PhaseId` = 26622;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15928, 26622, 'Har''mara - Allied Race start hub');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 26622 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 26622, 0, 0, 0, 16, 0, 0x180000, 0, 0, 0, 'Apply Phase 26622 if player is Race Haranir (A|H)'),
(26, 26622, 0, 0, 0, 47, 0, 90961, 64, 0, 1, 'Apply Phase 26622 if Quest 90961 is not rewarded');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (248904,251883,248789,248902,248895,248901,248905));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(248904, 1, 245691, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Har'mara Elder Root
(251883, 1, 251946, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Grove Protector Madar
(248789, 1, 232649, 0, 0, 232650, 0, 0, 0, 0, 0, 66838), -- Hannan
(248902, 1, 245691, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Har'mara Blossomsinger
(248895, 1, 180150, 0, 0, 0, 0, 0, 61320, 0, 0, 66838), -- Har'mara Sporeguard
(248901, 1, 252382, 0, 0, 254184, 0, 0, 254230, 0, 0, 66838), -- Har'mara Grove Protector
(248905, 1, 245691, 0, 0, 0, 0, 0, 0, 0, 0, 66838); -- Har'mara Grovewarden

-- Path for Vicious Saptor
SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 245114;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Vicious Saptor - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1118.7952, 886.533, 1344.5997, NULL, 4660),
(@PATH, 1, 1120.0695, 875.24133, 1343.8569, NULL, 1622),
(@PATH, 2, 1126.868, 880.0868, 1340.4802, 2.467528, 2506);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
