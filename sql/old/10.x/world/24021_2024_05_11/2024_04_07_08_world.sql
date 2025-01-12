SET @CGUID := 6000992;
SET @OGUID := 6000600;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+59;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1153.404541015625, 1687.4600830078125, 84.96288299560546875, 2.323044538497924804, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+1, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1218.2222900390625, 1654.2882080078125, 99.9712371826171875, 5.721107959747314453, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+2, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1157.732666015625, 1678.857666015625, 85.0324859619140625, 5.433307647705078125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+3, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1204.765625, 1676.1146240234375, 92.76692962646484375, 5.433307647705078125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+4, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1094.8785400390625, 1644.6822509765625, 113.9688644409179687, 1.628173112869262695, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+5, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1087.01220703125, 1643.16845703125, 114.8537521362304687, 5.211618423461914062, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+6, 97598, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1098.986083984375, 1711.4757080078125, 100.8897323608398437, 0.300731599330902099, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+7, 97601, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1097.13720703125, 1614.1597900390625, 116.800567626953125, 5.603891372680664062, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shivarra Destroyer (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+8, 101790, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1100.9478759765625, 1616.3055419921875, 116.7567596435546875, 5.147719383239746093, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 159474 - Permanent Feign Death (NO Stun, Untrackable; Immune))
(@CGUID+9, 99650, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1203.10595703125, 1675.4010009765625, 92.63629150390625, 3.239926576614379882, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Thornclaw Broodling (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+10, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1144.6163330078125, 1688.671875, 84.92425537109375, 5.56801605224609375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+11, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1146.4913330078125, 1675.314208984375, 84.96288299560546875, 0.706846773624420166, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+12, 102726, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1146.201416015625, 1683.126708984375, 84.96288299560546875, 0.174488350749015808, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Eredar Sorcerer (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+13, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1147.5035400390625, 1691.9774169921875, 84.9610137939453125, 5.031007766723632812, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+14, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1143.1180419921875, 1679.3004150390625, 84.962890625, 0.046507898718118667, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+15, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1142.44970703125, 1684.1649169921875, 84.9629058837890625, 6.239930629730224609, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 99650, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1175.0625, 1678.986083984375, 89.269195556640625, 5.446194648742675781, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Thornclaw Broodling (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+17, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1130.295166015625, 1740.798583984375, 92.80257415771484375, 5.285316944122314453, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+18, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1123.0364990234375, 1729.2916259765625, 92.860260009765625, 0.257599204778671264, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+19, 94655, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1152.90625, 1716.9739990234375, 86.6607208251953125, 4.765755653381347656, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Soul Leech (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+20, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1085.454833984375, 1691.5035400390625, 101.5756988525390625, 0.424238562583923339, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+21, 96473, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1128.154541015625, 1734.0103759765625, 92.8083343505859375, 5.907498359680175781, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Eredar Sorcerer (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+22, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1123.6910400390625, 1733.4097900390625, 92.6265869140625, 6.136211395263671875, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+23, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1128.5625, 1728.1180419921875, 92.96260833740234375, 0.687266170978546142, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+24, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1086.1458740234375, 1685.3177490234375, 101.3568191528320312, 1.047027111053466796, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+25, 99650, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1096.8333740234375, 1732.96875, 93.01416778564453125, 5.203153133392333984, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Thornclaw Broodling (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+26, 96473, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1090.77783203125, 1682.795166015625, 101.5313568115234375, 1.531443238258361816, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Eredar Sorcerer (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+27, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1125.486083984375, 1738.4478759765625, 92.32118988037109375, 5.865056037902832031, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 102726, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1070.15283203125, 1702.0711669921875, 109.8028488159179687, 5.321925640106201171, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Eredar Sorcerer (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+29, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1088.1961669921875, 1677.21875, 101.4673995971679687, 1.393428206443786621, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+30, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1082.5728759765625, 1680.1875, 101.300994873046875, 1.014788389205932617, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+31, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1096.486083984375, 1686.2117919921875, 101.3318939208984375, 2.158540010452270507, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+32, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1095.5660400390625, 1680.8992919921875, 101.3922271728515625, 1.396491646766662597, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+33, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1097.9757080078125, 1690.6319580078125, 101.1834259033203125, 2.136807441711425781, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+34, 99650, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1042.185791015625, 1701.6129150390625, 110.1502685546875, 4.605317115783691406, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Thornclaw Broodling (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+35, 94655, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1084.3697509765625, 1637.71875, 116.1748046875, 1.122428536415100097, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Soul Leech (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+36, 99650, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1102.9947509765625, 1670.0521240234375, 100.4947891235351562, 0.962094485759735107, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Thornclaw Broodling (Area: Cryptic Hollow - Difficulty: 0) CreateObject2
(@CGUID+37, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1126.7222900390625, 1714.8663330078125, 93.100372314453125, 1.293797731399536132, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+38, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1068.5816650390625, 1698.7742919921875, 110.0196762084960937, 5.712307453155517578, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+39, 102726, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1096.9410400390625, 1734.138916015625, 93.02582550048828125, 6.093934535980224609, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Eredar Sorcerer (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+40, 96494, 1481, 7705, 7754, '0', 5077, 0, 0, 2, 1159.8663330078125, 1719.4478759765625, 86.01751708984375, 4.00503396987915039, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+41, 96502, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1151.62158203125, 1679.6961669921875, 84.96288299560546875, 3.019590139389038085, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Coilskar Myrmidon (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+42, 96500, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1150.7239990234375, 1682.295166015625, 84.96288299560546875, 4.342205047607421875, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ashtongue Warrior (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+43, 101787, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1150.1910400390625, 1683.829833984375, 84.96288299560546875, 3.121726512908935546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+44, 101789, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1134.2899169921875, 1734.5347900390625, 92.73976898193359375, 2.381104707717895507, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+45, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1123.517333984375, 1620.8941650390625, 120.7570724487304687, 0.011622034944593906, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+46, 96502, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1137.07470703125, 1734.576416015625, 92.6215972900390625, 3.379358530044555664, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Coilskar Myrmidon (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+47, 96441, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1103.8055419921875, 1609.2847900390625, 116.7624664306640625, 1.886764407157897949, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Fel Lord Caza (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+48, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1109.7691650390625, 1633.2847900390625, 119.900482177734375, 0.735057473182678222, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+49, 101788, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1133.279541015625, 1731.9896240234375, 92.84519195556640625, 3.121726512908935546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+50, 96501, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1135.157958984375, 1732.982666015625, 92.7420501708984375, 3.07518172264099121, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ashtongue Mystic (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+51, 96503, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1094.3697509765625, 1696.3072509765625, 101.1974563598632812, 5.278429985046386718, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Coilskar Sea-Caller (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+52, 101787, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1092.3072509765625, 1695.04345703125, 101.25054931640625, 4.957291603088378906, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+53, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1122.91845703125, 1606.984375, 120.8116226196289062, 5.580253124237060546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+54, 96500, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1088.9913330078125, 1696.0816650390625, 101.2800674438476562, 5.911265850067138671, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Ashtongue Warrior (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+55, 96499, 1481, 7705, 7754, '0', 5077, 0, 0, 1, 1091.2239990234375, 1694.109375, 101.2683029174804687, 5.811895370483398437, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Jace Darkweaver (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+56, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1103.298583984375, 1633.8489990234375, 119.6934738159179687, 1.486257433891296386, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+57, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1083.1197509765625, 1623.15283203125, 120.7178878784179687, 2.738939762115478515, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+58, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1083.0538330078125, 1612.41845703125, 120.86004638671875, 3.089210271835327148, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+59, 100061, 1481, 7705, 7754, '0', 5077, 0, 0, 0, 1089.2552490234375, 1599.3697509765625, 121.279022216796875, 3.655777454376220703, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989); -- Axe Throw Stalker (Area: Cryptic Hollow - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+59;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+1, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+2, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+3, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+4, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+5, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+6, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Butcher - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+7, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Shivarra Destroyer - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+8, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '222589 159474'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 159474 - Permanent Feign Death (NO Stun, Untrackable; Immune
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Eredar Sorcerer
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Felguard Butcher
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Felguard Butcher
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Eredar Sorcerer
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''); -- Felguard Butcher

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 246401, 1481, 7705, 7754, '0', 5077, 0, 1115.490234375, 1589.3299560546875, 116.1777572631835937, 2.073857784271240234, 0, 0, 0.860845565795898437, 0.508866310119628906, 120, 255, 0, 53989); -- Doodad_7LG_Legion_Portal002 (Area: Cryptic Hollow - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.973379254341125488, 0.22920025885105133, 0, 0); -- Doodad_7LG_Legion_Portal002

-- Template
UPDATE `creature_template` SET `unit_flags3`=16777216, `flags_extra` = 128 WHERE `entry`=100061; -- Axe Throw Stalker
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=96441; -- Fel Lord Caza

UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=53989 WHERE `entry`=246401; -- Doodad_7LG_Legion_Portal002

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (96441 /*96441 (Fel Lord Caza)*/, 100061 /*100061 (Axe Throw Stalker)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(96441, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 96441 (Fel Lord Caza)
(100061, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 100061 (Axe Throw Stalker)

DELETE FROM `gameobject_template_addon` WHERE `entry` = (246401 /*Doodad_7LG_Legion_Portal002*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(246401, 114, 0, 0, 0); -- Doodad_7LG_Legion_Portal002

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53989 WHERE (`Entry`=96441 AND `DifficultyID`=0); -- Fel Lord Caza
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=53989 WHERE (`Entry`=100061 AND `DifficultyID`=0); -- Axe Throw Stalker

-- Phasing
DELETE FROM `phase_area` WHERE (`PhaseId` = 5077 AND `AreaId` = 7705);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5077, 'Cryptic Hollow NPCs inside cave for quest Hidden No More');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5077 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5077, 0, 0, 0, 47, 0, 39495, 2|8|64, 0, 0, 'Apply Phase 5077 if Quest 39495 is in progress | complete | rewarded');
