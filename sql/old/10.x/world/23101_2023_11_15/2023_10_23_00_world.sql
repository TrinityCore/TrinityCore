SET @CGUID := 6000683;
SET @OGUID := 6000176;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+86;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 96400, 1481, 7705, 7826, '0', 0, 0, 0, 1, 1206.923583984375, 2561.2744140625, -3.83307623863220214, 3.18723464012145996, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Mo'arg Brute (Area: Twisting Nether - Difficulty: 0) CreateObject2
(@CGUID+1, 94654, 1481, 7705, 7826, '0', 0, 0, 0, 1, 1112.2413330078125, 2561.56591796875, -27.921518325805664, 3.501039028167724609, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Doomguard Eradicator (Area: Twisting Nether - Difficulty: 0) CreateObject2
(@CGUID+2, 94654, 1481, 7705, 7826, '0', 0, 0, 0, 1, 1116.4114990234375, 2546.2353515625, -25.8243598937988281, 2.886753797531127929, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Doomguard Eradicator (Area: Twisting Nether - Difficulty: 0) CreateObject2
(@CGUID+3, 99656, 1481, 7705, 7826, '0', 0, 0, 0, 0, 1183.19970703125, 2558.803955078125, -9.53860855102539062, 5.097788810729980468, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51536), -- Red Broodling (Area: Twisting Nether - Difficulty: 0) CreateObject2
(@CGUID+4, 96400, 1481, 7705, 7826, '0', 0, 0, 0, 1, 1221.920166015625, 2562.913330078125, -0.86501979827880859, 3.096717357635498046, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Mo'arg Brute (Area: Twisting Nether - Difficulty: 0) CreateObject2
(@CGUID+5, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1241.5382080078125, 2521.84033203125, 0.612438678741455078, 0.162328720092773437, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+6, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1335.1458740234375, 2530.833251953125, 28.597930908203125, 4.007552623748779296, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+7, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1311.907958984375, 2546.686767578125, 21.35969734191894531, 0.978776395320892333, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+8, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1242.3941650390625, 2524.540771484375, 0.78324437141418457, 2.537512540817260742, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+9, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1277.76220703125, 2584.221435546875, 10.17075157165527343, 0.517586946487426757, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+10, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1295.8663330078125, 2540.724853515625, 15.1292724609375, 2.664046287536621093, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+11, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1246.74658203125, 2606.978271484375, 13.44624900817871093, 3.276155471801757812, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+12, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1249.78125, 2535.86279296875, 1.949370980262756347, 2.763540983200073242, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+13, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1276.546875, 2590.358642578125, 10.19445228576660156, 0.098232828080654144, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+14, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1252.7691650390625, 2577.03466796875, 6.229153633117675781, 3.668339967727661132, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+15, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1322.671875, 2526.611083984375, 25.734375, 5.841054916381835937, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+16, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1383.8819580078125, 2604.268310546875, 23.56549835205078125, 5.760746479034423828, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+17, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1337.3646240234375, 2596.704833984375, 17.03594398498535156, 4.517617225646972656, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+18, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1359.982666015625, 2568.132080078125, 21.79096221923828125, 3.097388505935668945, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+19, 99650, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1382.34033203125, 2487.282958984375, 21.71718215942382812, 4.472590923309326171, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Thornclaw Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+20, 96400, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1352.3629150390625, 2558.826416015625, 18.63431739807128906, 5.501952171325683593, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Mo'arg Brute (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+21, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1394.8472900390625, 2632.342041015625, 26.47126007080078125, 3.709954500198364257, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+22, 99656, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1378.3489990234375, 2549.2900390625, 19.6994476318359375, 3.253567457199096679, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Red Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+23, 96400, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1366.76220703125, 2472.942626953125, 15.02314186096191406, 1.528586864471435546, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Mo'arg Brute (Area: Seat of Command - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1411.32470703125, 2590.819580078125, 25.37152862548828125, 3.215126276016235351, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+25, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1406.154541015625, 2580.166748046875, 26.65080642700195312, 2.224669218063354492, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+26, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1408.501708984375, 2603.46533203125, 25.71006965637207031, 3.605747938156127929, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+27, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1382.2916259765625, 2617.94091796875, 20.86171913146972656, 2.206801414489746093, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1446.451416015625, 2615.447998046875, 30.430633544921875, 4.482771873474121093, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+29, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1412.0364990234375, 2541.454833984375, 31.2383880615234375, 5.997949123382568359, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+30, 94705, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1398.6961669921875, 2589.892333984375, 23.44754981994628906, 5.366484642028808593, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Demon Hunter (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+31, 99656, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1450.7708740234375, 2548.068603515625, 35.21951675415039062, 1.14580690860748291, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Red Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+32, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1407.3004150390625, 2627.3056640625, 26.338775634765625, 1.894154667854309082, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+33, 94705, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1398.66845703125, 2594.756103515625, 23.37772178649902343, 0.724686026573181152, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Demon Hunter (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+34, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1424.6978759765625, 2550.510498046875, 31.23317527770996093, 4.523648738861083984, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+35, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1409.8385009765625, 2630.662353515625, 26.60472297668457031, 2.416439533233642578, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+36, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1500.3021240234375, 2611.998291015625, 31.95060920715332031, 0.15995904803276062, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+37, 99650, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1518.921875, 2676.632080078125, 29.05729293823242187, 5.410716533660888671, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Thornclaw Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+38, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1526.6336669921875, 2536.31689453125, 51.66840362548828125, 3.309560060501098632, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+39, 99650, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1578.7100830078125, 2616.1337890625, 33.02614212036132812, 4.336198806762695312, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Thornclaw Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+40, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1551.7535400390625, 2655.09716796875, 26.02239418029785156, 3.980147123336791992, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+41, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1516.1129150390625, 2614.65185546875, 31.6948699951171875, 10, 120, 0, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+42, 95046, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1506.88720703125, 2623.216064453125, 30.29318618774414062, 4.678340435028076171, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+43, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1578.1666259765625, 2643.53466796875, 26.0027923583984375, 2.945236682891845703, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+44, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1559.1805419921875, 2578.58251953125, 48.37430191040039062, 1.60968482494354248, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+45, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1454.91845703125, 2649.213623046875, 36.98752593994140625, 4.360714435577392578, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject1
(@CGUID+46, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1464.9375, 2651.799560546875, 34.56757354736328125, 4.302892684936523437, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject1
(@CGUID+47, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1478.5677490234375, 2575.053955078125, 38.96307373046875, 3.165602684020996093, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject1
(@CGUID+48, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1526.3367919921875, 2677.15966796875, 26.03546905517578125, 4.309673786163330078, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject1
(@CGUID+49, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1521.54345703125, 2527.7666015625, 51.97048568725585937, 2.391044139862060546, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+50, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1526.6336669921875, 2536.31689453125, 51.66840362548828125, 4.080859184265136718, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+51, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1476.907958984375, 2539.2509765625, 42.13460922241210937, 2.512189149856567382, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+52, 99656, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1512.5660400390625, 2547.02783203125, 48.53463363647460937, 0.317383855581283569, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Red Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+53, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1470.5416259765625, 2533.564208984375, 41.25586700439453125, 1.90260171890258789, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+54, 94705, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1514.564208984375, 2534.278564453125, 50.34027862548828125, 5.532298088073730468, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Demon Hunter (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+55, 98622, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1594.638916015625, 2543.140625, 62.10567855834960937, 0.53136986494064331, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Mo'arg Brute (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+56, 97594, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1595.3125, 2555.427978515625, 64.3707733154296875, 2.266414403915405273, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+57, 98611, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1592.107666015625, 2537.638916015625, 62.10352325439453125, 0.219361379742622375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+58, 97594, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1584.5399169921875, 2546.749267578125, 62.10065841674804687, 3.809655666351318359, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+59, 98622, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1619.7603759765625, 2528.857666015625, 72.94498443603515625, 3.556628704071044921, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Mo'arg Brute (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+60, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1552.767333984375, 2431.663330078125, 73.2015838623046875, 4.288712978363037109, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+61, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1551.9305419921875, 2477.5087890625, 61.46788787841796875, 0.573628902435302734, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+62, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1587.4322509765625, 2414.98095703125, 85.2004547119140625, 3.128184318542480468, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+63, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1535.3004150390625, 2422.663330078125, 70.73370361328125, 0.178509563207626342, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+64, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1430.84033203125, 2472.833251953125, 41.832855224609375, 2.577353239059448242, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+65, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1462.3680419921875, 2473.32470703125, 45.42657470703125, 2.47539377212524414, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+66, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1468.3819580078125, 2499.15283203125, 42.53853607177734375, 5.653721809387207031, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+67, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1445.52783203125, 2409.59716796875, 55.54343795776367187, 6.1461944580078125, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+68, 99650, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1449.6180419921875, 2482.166748046875, 42.24767684936523437, 1.325057625770568847, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Thornclaw Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+69, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1419.296875, 2444.920166015625, 45.150970458984375, 3.252623558044433593, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+70, 102714, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1419.4757080078125, 2447.19091796875, 44.9452056884765625, 3.37312626838684082, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51754), -- Eredar Summoner (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 188560 - Eredar Summoner: Fel Channel Omni)
(@CGUID+71, 96400, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1480.0372314453125, 2487.156005859375, 46.71103286743164062, 5.320156097412109375, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Mo'arg Brute (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+72, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1461.55908203125, 2315.460205078125, 85.76751708984375, 3.801587581634521484, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+73, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1378.951416015625, 2349.913330078125, 56.1681976318359375, 4.681694984436035156, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+74, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1444.8004150390625, 2286.1875, 92.1107940673828125, 2.606513023376464843, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+75, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1428.6666259765625, 2341.7587890625, 65.46014404296875, 1.433168888092041015, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+76, 99650, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1445.142333984375, 2352.1025390625, 66.020965576171875, 5.968822002410888671, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Thornclaw Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+77, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1453.3819580078125, 2295.69091796875, 91.298492431640625, 5.546298980712890625, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+78, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1438.767333984375, 2308.704833984375, 83.06501007080078125, 2.726120233535766601, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+79, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1343.84033203125, 2385.43408203125, 37.53708648681640625, 6.199746131896972656, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject1
(@CGUID+80, 94654, 1481, 7705, 7742, '0', 0, 0, 0, 1, 1346.4774169921875, 2376.09716796875, 38.92360305786132812, 0.008943960070610046, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Doomguard Eradicator (Area: Seat of Command - Difficulty: 0) CreateObject1
(@CGUID+81, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1385.6632080078125, 2356.048583984375, 57.77831268310546875, 0.477360427379608154, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+82, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1276.5694580078125, 2426.223876953125, 7.155234813690185546, 1.751578211784362792, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+83, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1312.1805419921875, 2347.09375, 29.31879806518554687, 4.449570655822753906, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+84, 94655, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1251.232666015625, 2415.911376953125, -8.57537746429443359, 4.874027252197265625, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Soul Leech (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+85, 99656, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1312.376708984375, 2414.741455078125, 25.09440803527832031, 1.823945522308349609, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Red Broodling (Area: Seat of Command - Difficulty: 0) CreateObject2
(@CGUID+86, 93115, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1291.1805419921875, 2338.854248046875, 21.16998291015625, 5.668088436126708984, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51754); -- Foul Felstalker (Area: Seat of Command - Difficulty: 0) CreateObject2 (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+86;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+2, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+12, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+18, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doomguard Eradicator - 151597 - No NPC Damage Below 45-90%
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doomguard Eradicator - 151597 - No NPC Damage Below 45-90%
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doomguard Eradicator - 151597 - No NPC Damage Below 45-90%
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+43, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+47, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+48, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Doomguard Eradicator
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doomguard Eradicator - 151597 - No NPC Damage Below 45-90%
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Foul Felstalker - 151597 - No NPC Damage Below 45-90%
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '188560'), -- Eredar Summoner - 188560 - Eredar Summoner: Fel Channel Omni
(@CGUID+75, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Doomguard Eradicator

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 246567, 1481, 7705, 7742, '0', 0, 0, 1622.576416015625, 2689.236083984375, 16.59150123596191406, 6.126105785369873046, -0.02056121826171875, -0.02697086334228515, -0.07893657684326171, 0.996302545070648193, 120, 255, 1, 51754), -- Spire of Woe B (Area: Seat of Command - Difficulty: 0) CreateObject1
(@OGUID+1, 246566, 1481, 7705, 7742, '0', 0, 0, 1571.0572509765625, 2724.83154296875, 16.93893051147460937, 4.9218292236328125, -0.00999164581298828, -0.01214981079101562, -0.62924385070800781, 0.777048707008361816, 120, 255, 1, 51754), -- Spire of Woe A (Area: Seat of Command - Difficulty: 0) CreateObject1
(@OGUID+2, 241757, 1481, 7705, 7742, '0', 0, 0, 1614.970458984375, 2518.041748046875, 73.3251953125, 2.696418046951293945, -0.00535964965820312, -0.0401010513305664, 0.974498748779296875, 0.220715686678886413, 120, 255, 1, 51754); -- Legion Gateway Activator (Area: Seat of Command - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 98611;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(98611, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- 98611 (Doomguard Eradicator) - Permanent Feign Death (NO Stun, Untrackable, Immune)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (246566 /*Spire of Woe A*/, 246567 /*Spire of Woe B*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(246566, 114, 32, 0, 0), -- Spire of Woe A
(246567, 114, 32, 0, 0); -- Spire of Woe B

-- Template updates
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51754 WHERE `entry`=241757; -- Legion Gateway Activator
UPDATE `gameobject_template` SET `VerifiedBuild`=51754 WHERE `entry` IN (244441, 246356);
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51754 WHERE `entry` IN (244604, 244601); -- Spire Stabilizer
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51754 WHERE `entry`=246567; -- Spire of Woe B
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51754 WHERE `entry`=246566; -- Spire of Woe A

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 94654;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(94654, 2, 0, 0, 0, 0, 0, NULL);

DELETE FROM `creature_movement_override` WHERE `SpawnId` IN (@CGUID+10, @CGUID+12, @CGUID+17, @CGUID+24, @CGUID+25, @CGUID+26, @CGUID+38, @CGUID+40, @CGUID+44, @CGUID+46, @CGUID+49, @CGUID+53, @CGUID+80);
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@CGUID+10, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+12, 1, 0, 1, 0, 0, 0, NULL),
(@CGUID+17, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+24, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+25, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+26, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+38, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+40, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+44, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+46, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+49, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+53, 1, 0, 0, 0, 0, 0, NULL),
(@CGUID+80, 1, 0, 0, 0, 0, 0, NULL);

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (94668,101696));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(94668, 0, 0, 0, 699, 6, 1, 1, 94695, 0, 0, 51754), -- Dread Felbat
(101696, 0, 0, 0, 699, 6, 1, 0.008276780135929584, 102298, 2097256, 0, 51754); -- Shadow Portal

-- Demons smartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (94654, 93115);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+26), -(@CGUID+25), -(@CGUID+24), -(@CGUID+50), -(@CGUID+49));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+26), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 15 yards: Start Attack'),
(-(@CGUID+25), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 15 yards: Start Attack'),
(-(@CGUID+24), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 15 yards: Start Attack'),
(-(@CGUID+50), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 15 yards: Start Attack'),
(-(@CGUID+49), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 15, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 15 yards: Start Attack');

-- Waypoints for CGUID+0
SET @ENTRY := 96400;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1178.311, 2559.7, -10.9325, NULL, 0),
(@PATH, 1, 1163.014, 2558.54, -14.86573, NULL, 0),
(@PATH, 2, 1149.405, 2557.006, -18.39911, NULL, 0),
(@PATH, 3, 1136.858, 2555.714, -21.47543, NULL, 0),
(@PATH, 4, 1125.49, 2553.109, -23.76696, NULL, 0),
(@PATH, 5, 1120.591, 2554.396, -24.99879, NULL, 11453),
(@PATH, 6, 1125.49, 2553.109, -23.76696, NULL, 0),
(@PATH, 7, 1136.858, 2555.714, -21.47543, NULL, 0),
(@PATH, 8, 1149.405, 2557.006, -18.39911, NULL, 0),
(@PATH, 9, 1163.014, 2558.54, -14.86573, NULL, 0),
(@PATH, 10, 1178.311, 2559.7, -10.9325, NULL, 0),
(@PATH, 11, 1192.851, 2560.632, -7.354753, NULL, 0),
(@PATH, 12, 1206.84, 2561.365, -3.799161, NULL, 11433),
(@PATH, 13, 1192.851, 2560.632, -7.354753, NULL, 0);

UPDATE `creature` SET `position_x`= 1178.311, `position_y`= 2559.7, `position_z`= -10.9325, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+0, @PATH, 1);

-- Waypoints for CGUID+8
SET @ENTRY := 102714;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1240.54, 2534.679, 0.4776404, NULL, 0),
(@PATH, 1, 1243.847, 2540.286, 1.059196, NULL, 0),
(@PATH, 2, 1248.536, 2545.627, 2.744166, NULL, 0),
(@PATH, 3, 1256.089, 2551.439, 4.853552, NULL, 0),
(@PATH, 4, 1271.035, 2558.892, 7.92443, NULL, 0),
(@PATH, 5, 1281.566, 2565.873, 10.09159, NULL, 0),
(@PATH, 6, 1289.236, 2572.622, 10.93637, NULL, 0),
(@PATH, 7, 1291.931, 2578.288, 10.29645, NULL, 0),
(@PATH, 8, 1291.252, 2582.221, 10.12682, NULL, 16574),
(@PATH, 9, 1289.236, 2572.622, 10.93637, NULL, 0),
(@PATH, 10, 1281.566, 2565.873, 10.09159, NULL, 0),
(@PATH, 11, 1271.035, 2558.892, 7.92443, NULL, 0),
(@PATH, 12, 1256.089, 2551.439, 4.853552, NULL, 0),
(@PATH, 13, 1248.536, 2545.627, 2.744166, NULL, 0),
(@PATH, 14, 1243.915, 2540.363, 1.010715, NULL, 0),
(@PATH, 15, 1240.54, 2534.679, 0.4776404, NULL, 0),
(@PATH, 16, 1239.083, 2530.208, -0.02824822, NULL, 0),
(@PATH, 17, 1240.377, 2525.933, 0.2697847, NULL, 0),
(@PATH, 18, 1242.396, 2524.563, 0.719978, NULL, 15032),
(@PATH, 19, 1239.083, 2530.208, -0.02824822, NULL, 0);

UPDATE `creature` SET `position_x`= 1240.54, `position_y`= 2534.679, `position_z`= 0.4776404, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+8;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+8;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+8, @PATH, 1);

-- Waypoints for CGUID+20
SET @ENTRY := 96400;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1368.019, 2542.067, 18.18399, NULL, 0),
(@PATH, 1, 1372.665, 2530.703, 19.14632, NULL, 0),
(@PATH, 2, 1373.597, 2519.653, 18.43173, NULL, 0),
(@PATH, 3, 1370.807, 2513.042, 17.71579, NULL, 0),
(@PATH, 4, 1366.686, 2504.343, 16.98316, NULL, 0),
(@PATH, 5, 1365.696, 2492.125, 14.19017, NULL, 0),
(@PATH, 6, 1366.316, 2483.049, 15.67877, NULL, 19330),
(@PATH, 7, 1365.696, 2492.125, 14.19017, NULL, 0),
(@PATH, 8, 1366.686, 2504.343, 16.98316, NULL, 0),
(@PATH, 9, 1370.807, 2513.042, 17.71579, NULL, 0),
(@PATH, 10, 1373.597, 2519.653, 18.43173, NULL, 0),
(@PATH, 11, 1372.665, 2530.703, 19.14632, NULL, 0),
(@PATH, 12, 1368.019, 2542.067, 18.18399, NULL, 0),
(@PATH, 13, 1361.894, 2549.376, 18.15317, NULL, 0),
(@PATH, 14, 1352.399, 2558.882, 18.56054, NULL, 16054),
(@PATH, 15, 1361.894, 2549.376, 18.15317, NULL, 0);

UPDATE `creature` SET `position_x`= 1368.019, `position_y`= 2542.067, `position_z`= 18.18399, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+20;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+20, @PATH, 1);

-- Waypoints for CGUID+21
SET @ENTRY := 102714;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1387.155, 2627.885, 23.26914, NULL, 0),
(@PATH, 1, 1380.927, 2621.72, 21.34353, NULL, 0),
(@PATH, 2, 1373.679, 2617.097, 20.71602, NULL, 0),
(@PATH, 3, 1365.544, 2611.277, 20.28286, NULL, 0),
(@PATH, 4, 1354.738, 2601.365, 19.81082, NULL, 0),
(@PATH, 5, 1348.941, 2595.465, 19.09051, NULL, 0),
(@PATH, 6, 1345.264, 2592.556, 17.82831, NULL, 20046),
(@PATH, 7, 1348.941, 2595.465, 19.09051, NULL, 0),
(@PATH, 8, 1354.738, 2601.365, 19.81082, NULL, 0),
(@PATH, 9, 1365.5, 2611.242, 20.30429, NULL, 0),
(@PATH, 10, 1373.635, 2617.063, 20.72194, NULL, 0),
(@PATH, 11, 1380.927, 2621.72, 21.34353, NULL, 0),
(@PATH, 12, 1387.155, 2627.885, 23.26914, NULL, 0),
(@PATH, 13, 1392.144, 2630.615, 25.6891, NULL, 0),
(@PATH, 14, 1394.875, 2632.385, 26.38538, NULL, 18524);

UPDATE `creature` SET `position_x`= 1387.155, `position_y`= 2627.885, `position_z`= 23.26914, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+21;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+21;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+21, @PATH, 1);

-- Waypoints for CGUID+38
SET @ENTRY := 94654;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1526.889, 2549.924, 51.20675, NULL, 0),
(@PATH, 1, 1512.823, 2547.659, 48.42096, NULL, 0),
(@PATH, 2, 1499.452, 2551.802, 45.27423, NULL, 0),
(@PATH, 3, 1477.715, 2563.542, 38.39419, NULL, 0),
(@PATH, 4, 1462.021, 2578.262, 34.78012, NULL, 0),
(@PATH, 5, 1453.76, 2587.917, 32.5055, NULL, 0),
(@PATH, 6, 1451.47, 2595.472, 31.77096, NULL, 0),
(@PATH, 7, 1454.302, 2605.523, 31.52847, NULL, 0),
(@PATH, 8, 1460.674, 2612.102, 32.32309, NULL, 0),
(@PATH, 9, 1469.34, 2617.306, 32.27563, NULL, 0),
(@PATH, 10, 1478.424, 2623.879, 31.66271, NULL, 0),
(@PATH, 11, 1494.095, 2631.55, 29.52293, NULL, 0),
(@PATH, 12, 1503.578, 2637.897, 28.44804, NULL, 0),
(@PATH, 13, 1515.341, 2647.213, 27.63075, NULL, 0),
(@PATH, 14, 1525.01, 2651.315, 27.11735, NULL, 0),
(@PATH, 15, 1535.29, 2648.483, 26.74705, NULL, 0),
(@PATH, 16, 1545.766, 2643.305, 26.62537, NULL, 0),
(@PATH, 17, 1554.991, 2635.236, 28.62637, NULL, 0),
(@PATH, 18, 1564.806, 2621.767, 31.85411, NULL, 0),
(@PATH, 19, 1561.674, 2611.612, 36.48868, NULL, 0),
(@PATH, 20, 1554.108, 2600.731, 42.23135, NULL, 0),
(@PATH, 21, 1544.931, 2584.849, 47.47111, NULL, 0),
(@PATH, 22, 1538.889, 2571.344, 50.8758, NULL, 0),
(@PATH, 23, 1533.578, 2557.001, 52.09231, NULL, 0);

UPDATE `creature` SET `position_x`= 1526.889, `position_y`= 2549.924, `position_z`= 51.20675, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+38;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+38;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+38, @PATH, 1);

-- Waypoints for CGUID+71
SET @ENTRY := 96400;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1478.91, 2488.776, 46.25843, NULL, 0),
(@PATH, 1, 1485.273, 2479.628, 48.51038, NULL, 0),
(@PATH, 2, 1493.366, 2471.137, 51.19431, NULL, 0),
(@PATH, 3, 1504.964, 2465.668, 53.70077, NULL, 0),
(@PATH, 4, 1514.391, 2464.195, 55.10551, NULL, 0),
(@PATH, 5, 1524.342, 2470.436, 55.34238, NULL, 0),
(@PATH, 6, 1531.526, 2482.776, 56.19398, NULL, 0),
(@PATH, 7, 1533.432, 2496.858, 55.12287, NULL, 0),
(@PATH, 8, 1524.149, 2514.62, 53.47953, NULL, 0),
(@PATH, 9, 1515.842, 2523.859, 51.25691, NULL, 0),
(@PATH, 10, 1506.297, 2528.61, 49.06406, NULL, 0),
(@PATH, 11, 1495.866, 2530.431, 46.86978, NULL, 0),
(@PATH, 12, 1486.799, 2528.922, 45.43649, NULL, 0),
(@PATH, 13, 1482.524, 2523.519, 44.91462, NULL, 0),
(@PATH, 14, 1477.771, 2507.563, 44.52412, NULL, 0);

UPDATE `creature` SET `position_x`= 1478.91, `position_y`= 2488.776, `position_z`= 46.25843, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+71;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+71;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+71, @PATH, 1);
