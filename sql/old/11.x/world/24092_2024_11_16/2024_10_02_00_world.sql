SET @CGUID := 10002854;
SET @OGUID := 10000878;

SET @ATSPAWNID := 98;
SET @ATPROPERTIESID := 84;

SET @NPCTEXTID := 600037;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+207;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1663.1510009765625, -830.7117919921875, -1249.68603515625, 5.129299163818359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+1, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1705.5972900390625, -830.04168701171875, -1249.5911865234375, 3.76602339744567871, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+2, 211152, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1601.111083984375, -805.14581298828125, -1247.5970458984375, 3.378552675247192382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+3, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1616.18896484375, -898.90771484375, -1249.4818115234375, 4.663950920104980468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1691.3194580078125, -868.03125, -1249.4166259765625, 3.390848636627197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+5, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1713.5677490234375, -827.029541015625, -1249.556884765625, 4.852000713348388671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+6, 211111, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1602.7222900390625, -808.3367919921875, -1247.01416015625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+7, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1703.482666015625, -836.61981201171875, -1249.536865234375, 3.073624610900878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+8, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1673.8629150390625, -867.47918701171875, -1249.3182373046875, 3.881436586380004882, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+9, 211137, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1603.3836669921875, -811.52606201171875, -1246.7064208984375, 3.378552675247192382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+10, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1677.6771240234375, -866.984375, -1249.4049072265625, 6.139864444732666015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+11, 224321, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1658.9444580078125, -839.9375, -1249.6395263671875, 1.867597103118896484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Ves'ka (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+12, 224320, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1631.3541259765625, -840.28643798828125, -1249.853515625, 5.531796932220458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Tes'ka (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+13, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1662.0521240234375, -820.86456298828125, -1249.752197265625, 4.982732772827148437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+14, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1716.3836669921875, -830.41143798828125, -1249.496337890625, 5.377855300903320312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+15, 211149, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1606.920166015625, -808.91839599609375, -1246.7078857421875, 3.378552675247192382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+16, 210932, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1626.0364990234375, -811.97918701171875, -1250.47265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+17, 211151, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1603.782958984375, -805.7725830078125, -1247.5970458984375, 3.378552675247192382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+18, 211150, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1599.8385009765625, -810.484375, -1247.5970458984375, 3.378552675247192382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+19, 210933, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1626.0364990234375, -811.97918701171875, -1250.47265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+20, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1611.950927734375, -899.1156005859375, -1249.48046875, 4.663784027099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1657.5711669921875, -987.37677001953125, -1244.119384765625, 3.117302417755126953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1723.80908203125, -801.84375, -1249.465576171875, 3.031310081481933593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+23, 210931, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1680.2569580078125, -906.44268798828125, -1249.3917236328125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+24, 224327, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1656.2603759765625, -923.1944580078125, -1249.615478515625, 4.701198577880859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Violesca (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+25, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1738.4322509765625, -793.50518798828125, -1249.6370849609375, 5.455217838287353515, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+26, 216619, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1865.6805419921875, -1126.501708984375, -1244.044677734375, 0.78567671775817871, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Orator Krix'vizk (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 454689 - Oration, 422356 - Bot AI Follow Advert)
(@CGUID+27, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1666.8941650390625, -991.19793701171875, -1244.12841796875, 1.998021125793457031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+28, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1751.5850830078125, -793.20660400390625, -1249.6475830078125, 5.717790603637695312, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+29, 224324, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1706.8853759765625, -875.88714599609375, -1249.4178466796875, 0.097100451588630676, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Silkswooner Waree (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+30, 210930, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1680.4879150390625, -905.43927001953125, -1249.390869140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+31, 220782, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1755.8021240234375, -1014.30377197265625, -1243.744384765625, 5.849663257598876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Stalker (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+32, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1732.1510009765625, -989.5006103515625, -1244.190673828125, 5.482946395874023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+33, 223254, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1711.296875, -834.7586669921875, -1246.4166259765625, 0.77948915958404541, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Queen Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 434389 - [DNT] Holographic Emitter Projection, 448290 - [DNT] Ready to Sabotage)
(@CGUID+34, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1614.17236328125, -901.13134765625, -1249.4818115234375, 4.663349628448486328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1714.4322509765625, -931.045166015625, -1249.531494140625, 0.723576605319976806, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+36, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1653.8038330078125, -935.5625, -1249.6639404296875, 1.6391143798828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+37, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1728.1441650390625, -804.66668701171875, -1249.51806640625, 2.600945472717285156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+38, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1695.90625, -875.24652099609375, -1249.41162109375, 3.256501197814941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+39, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1733.5347900390625, -816.87677001953125, -1249.5010986328125, 2.335427761077880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+40, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1710.2379150390625, -911.06427001953125, -1249.4207763671875, 1.533496618270874023, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+41, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1689.5728759765625, -883.06768798828125, -1249.4010009765625, 2.969115734100341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+42, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1726.9879150390625, -810.20831298828125, -1249.5361328125, 2.614666461944580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+43, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1746.8350830078125, -805.734375, -1249.515625, 5.753625392913818359, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+44, 204401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1688.8541259765625, -933.2257080078125, -1249.419677734375, 2.804758071899414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Stalker (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+45, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1730.9322509765625, -812.42706298828125, -1249.5325927734375, 2.229527711868286132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+46, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1775.6978759765625, -935.94964599609375, -1244.4931640625, 2.360459804534912109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+47, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1790.85595703125, -936.6875, -1244.4554443359375, 0.953358948230743408, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+48, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1719.66845703125, -988.513916015625, -1244.131103515625, 0.66619187593460083, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+49, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1706.7034912109375, -915.0770263671875, -1249.503662109375, 0.769784331321716308, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1700.7274169921875, -924.8194580078125, -1249.42236328125, 0.058783851563930511, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+51, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1717.8106689453125, -923.74078369140625, -1249.56787109375, 4.173537254333496093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1707.623046875, -936.139892578125, -1249.5751953125, 6.259871482849121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 210931, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1765.8785400390625, -1017.951416015625, -1243.626708984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+54, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1783.1510009765625, -944.01739501953125, -1244.2652587890625, 1.438396215438842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+55, 210930, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1766.111083984375, -1018.45489501953125, -1243.6131591796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+56, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1783.6754150390625, -929.64410400390625, -1244.5577392578125, 4.713746547698974609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+57, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1642.685791015625, -1008.1995849609375, -1244.173828125, 5.990681648254394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+58, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1646.25, -1017.18048095703125, -1244.1422119140625, 0.266959518194198608, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+59, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1801.8125, -1003.046875, -1243.939208984375, 3.394571542739868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+60, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1882.7603759765625, -876.40106201171875, -1244.13134765625, 4.641385555267333984, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+61, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1812.0242919921875, -983.50518798828125, -1244.0992431640625, 3.295854568481445312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+62, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1875.1788330078125, -883.99652099609375, -1244.13134765625, 4.365253925323486328, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+63, 224330, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1830.5885009765625, -919.3663330078125, -1244.13134765625, 4.99537515640258789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Maraclozh (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+64, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1814.689208984375, -991.467041015625, -1244.049072265625, 2.605270862579345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+65, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1774.7257080078125, -1022.3125, -1243.6129150390625, 0.555682957172393798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+66, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1765.1649169921875, -1025.09375, -1243.41357421875, 1.139127254486083984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+67, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1748.390625, -990.796875, -1244.059326171875, 3.875539302825927734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+68, 224331, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1816.35595703125, -935.27777099609375, -1244.13134765625, 4.785514354705810546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Phylleus (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+69, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1816.62158203125, -941.08331298828125, -1244.13134765625, 1.440869688987731933, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+70, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1754.9617919921875, -988.28125, -1244.019287109375, 4.377200603485107421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+71, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1642.9583740234375, -1026.5521240234375, -1244.22607421875, 0.296493977308273315, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1695.1336669921875, -1046.1944580078125, -1244.044677734375, 0.682063221931457519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+73, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1682.4896240234375, -1046.5347900390625, -1244.1314697265625, 2.221043348312377929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+74, 223254, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1757.79345703125, -999.44097900390625, -1239.9166259765625, 5.990448474884033203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Queen Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 434389 - [DNT] Holographic Emitter Projection, 448290 - [DNT] Ready to Sabotage)
(@CGUID+75, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1745.7552490234375, -999.295166015625, -1244.0146484375, 3.031972646713256835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+76, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1688.87158203125, -1039.171875, -1244.1435546875, 4.641083240509033203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+77, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1681.611083984375, -1000.89410400390625, -1244.1319580078125, 0, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+78, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1890.951416015625, -883.67706298828125, -1244.13134765625, 5.002051353454589843, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+79, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1749.2430419921875, -1005.2742919921875, -1243.93115234375, 2.657318115234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+80, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1715.30908203125, -983.23089599609375, -1244.1319580078125, 4.239999771118164062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+81, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1756.0242919921875, -1016.80548095703125, -1243.684814453125, 1.716678977012634277, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+82, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1766.1285400390625, -1012.0103759765625, -1243.7564697265625, 0.35662814974784851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+83, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1668.63720703125, -984.71875, -1244.1300048828125, 4.930068492889404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+84, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1691.6492919921875, -1002.75347900390625, -1244.134521484375, 2.098978757858276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+85, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1685.01220703125, -1001.921875, -1244.132080078125, 0.427975833415985107, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+86, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1681.032958984375, -1003.484375, -1244.1322021484375, 1.801822304725646972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+87, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1713.23876953125, -1002.76495361328125, -1244.2076416015625, 2.750760316848754882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+88, 220479, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1692.328125, -1001.56768798828125, -1244.133056640625, 0.827633202075958251, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Visiting Merchant (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+89, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1709.795166015625, -1007.07391357421875, -1244.1573486328125, 2.497970104217529296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1690.3541259765625, -1102.3541259765625, -1237.8385009765625, 6.254038333892822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+91, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1726.359375, -1002.712890625, -1244.1971435546875, 2.263892650604248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+92, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1721.1370849609375, -1005.5208740234375, -1244.2120361328125, 2.303457260131835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1676.3385009765625, -1097.8160400390625, -1237.845947265625, 5.216988563537597656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+94, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1749.6805419921875, -996.046875, -1244.016845703125, 3.572755098342895507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+95, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1752.8472900390625, -992.57293701171875, -1244.012939453125, 3.952591180801391601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+96, 224329, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1648.720458984375, -1056.1458740234375, -1243.83154296875, 5.600142478942871093, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Visiting Merchant (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+97, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1810.0711669921875, -1079.2239990234375, -1243.986083984375, 1.466837167739868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+98, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1680.8177490234375, -1113.4739990234375, -1237.845947265625, 0.315838128328323364, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+99, 220431, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1650.4879150390625, -1050.5, -1244.131103515625, 3.020642518997192382, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Visiting Merchant (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+100, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1644.4410400390625, -1049.6632080078125, -1243.8558349609375, 1.3815765380859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+101, 220479, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1644.0521240234375, -1047.8211669921875, -1243.9886474609375, 0.827633202075958251, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Visiting Merchant (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+102, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1651.9879150390625, -1049.2222900390625, -1244.1319580078125, 5.698003768920898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+103, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1648.6319580078125, -1055.578125, -1243.833740234375, 0.28301626443862915, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+104, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1725.234375, -1121.1944580078125, -1237.782470703125, 2.588637351989746093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+105, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1735.4583740234375, -1124.1788330078125, -1237.7877197265625, 1.871761202812194824, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+106, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1706.7447509765625, -1099.2742919921875, -1237.782470703125, 2.033716440200805664, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+107, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1734.7379150390625, -1140.5052490234375, -1237.845947265625, 1.615352630615234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+108, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1669.717041015625, -1109.6353759765625, -1237.845947265625, 3.405658483505249023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+109, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1744.7379150390625, -1128.279541015625, -1237.78125, 1.049659371376037597, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+110, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1750.7430419921875, -1012.2620849609375, -1243.8150634765625, 2.060404539108276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+111, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1676.5103759765625, -1148.38720703125, -1238.0963134765625, 6.067478656768798828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+112, 223254, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1668.43408203125, -1150.8160400390625, -1234.9166259765625, 3.096729993820190429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Queen Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 434389 - [DNT] Holographic Emitter Projection, 448290 - [DNT] Ready to Sabotage)
(@CGUID+113, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1756.4149169921875, -1010.31427001953125, -1243.8211669921875, 1.615673780441284179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+114, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1673.6441650390625, -1141.7552490234375, -1238.0269775390625, 5.20747232437133789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+115, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1704.595458984375, -1098.5989990234375, -1237.782470703125, 3.559981584548950195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+116, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1778.388916015625, -1144.7864990234375, -1237.845947265625, 5.761834144592285156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+117, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1739.064208984375, -1117.8160400390625, -1237.782470703125, 5.26511383056640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+118, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1730.8836669921875, -1116.0208740234375, -1237.8017578125, 5.550478458404541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+119, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1780.0225830078125, -1154.3367919921875, -1237.8455810546875, 0.159887671470642089, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+120, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1674.1597900390625, -1157.2117919921875, -1238.266845703125, 0.826463580131530761, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+121, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1718.16845703125, -1185.7847900390625, -1237.755859375, 5.445607185363769531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+122, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1681, -1153.673583984375, -1238.0390625, 0.415713042020797729, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+123, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1700.2650146484375, -1114.0286865234375, -1237.8658447265625, 4.13732767105102539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+124, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1757.96875, -1177.38720703125, -1237.755859375, 2.945818424224853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+125, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1691.959716796875, -1119.0289306640625, -1237.9293212890625, 2.092751979827880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+126, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1792.7916259765625, -1157.59375, -1237.8455810546875, 4.808313369750976562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+127, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1874.189208984375, -1053.421875, -1237.1339111328125, 1.633456230163574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+128, 220777, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2165.423583984375, -1174.326416015625, -1243.0269775390625, 6.257812976837158203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Executor Nizrek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 422359 - Bot AI Follow Advert)
(@CGUID+129, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1740.8055419921875, -1194.1007080078125, -1237.6209716796875, 4.14362955093383789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+130, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1828.32470703125, -1070.765625, -1244.033447265625, 0.849306583404541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+131, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1749.9097900390625, -1196.0538330078125, -1237.489501953125, 5.176761150360107421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+132, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1882.595458984375, -1043.8680419921875, -1237.1339111328125, 0.007699731271713972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+133, 225962, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1875.5191650390625, -1124.703125, -1244.0828857421875, 3.91831374168395996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 454706 - Advert)
(@CGUID+134, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1900.9832763671875, -994.86273193359375, -1237.21728515625, 5.956731319427490234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+135, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1791.2691650390625, -1145.1475830078125, -1237.845947265625, 5.803864002227783203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+136, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1719.2379150390625, -1174.076416015625, -1237.8392333984375, 0.564549267292022705, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+137, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1804.4727783203125, -1070.5140380859375, -1243.9681396484375, 2.235738754272460937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+138, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1812.3228759765625, -1010.63372802734375, -1243.9495849609375, 0.661073267459869384, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+139, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1727.5443115234375, -1130.2442626953125, -1237.8658447265625, 2.069136619567871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+140, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1823.1180419921875, -1060.1197509765625, -1244, 0.663568973541259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+141, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1809.982666015625, -1064.54345703125, -1243.8638916015625, 1.407976627349853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1830.9583740234375, -1116.01220703125, -1244.13134765625, 6.27968597412109375, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+143, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1817.007080078125, -1064.0201416015625, -1244.014892578125, 1.135360002517700195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+144, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1813.6944580078125, -1006.40802001953125, -1243.9339599609375, 6.160096168518066406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+145, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1816.1666259765625, -1009.33331298828125, -1243.904541015625, 0.434021204710006713, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+146, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1893.8541259765625, -1057.5208740234375, -1237.1339111328125, 4.60935211181640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+147, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1890.6458740234375, -983.01214599609375, -1237.1339111328125, 5.736667156219482421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+148, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1812.84033203125, -1002.3125, -1243.9559326171875, 6.154179573059082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+149, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1816.96533203125, -1004.0504150390625, -1243.90966796875, 0.013945376500487327, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+150, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1874.0521240234375, -1043.21875, -1237.1339111328125, 3.067096471786499023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+151, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1863.5538330078125, -1093.30908203125, -1244.044677734375, 6.278375625610351562, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+152, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1821.9322509765625, -985.9774169921875, -1244.1302490234375, 5.762904167175292968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+153, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1819.9410400390625, -1077.489501953125, -1244.1170654296875, 3.109651088714599609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+154, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1791.532958984375, -1161.9132080078125, -1237.625244140625, 5.703322410583496093, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+155, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1823.3785400390625, -1104.701416015625, -1244.13134765625, 1.557929515838623046, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+156, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1765.1285400390625, -1173.9375, -1237.8353271484375, 5.673969268798828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+157, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1922.9947509765625, -985.65106201171875, -1237.1339111328125, 2.600949048995971679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+158, 220195, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1920.40625, -976.43231201171875, -1237.1339111328125, 3.66917586326599121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Sureki Silkbinder (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+159, 220196, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1882.8125, -1054.51220703125, -1237.1339111328125, 3.969234943389892578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Herald of Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+160, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1825.0711669921875, -1103.8836669921875, -1244.13134765625, 6.020493030548095703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+161, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1836.458984375, -1066.666015625, -1244.1273193359375, 2.855762243270874023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+162, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1836.455078125, -1058.441650390625, -1244.1280517578125, 3.715945959091186523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+163, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1839.1214599609375, -1100.5052490234375, -1244.1766357421875, 2.94560551643371582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+164, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1893.74658203125, -1061.84033203125, -1237.1339111328125, 5.428517341613769531, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+165, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1843.646728515625, -1091.1446533203125, -1244.19921875, 0.498046576976776123, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+166, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1887.1597900390625, -983.217041015625, -1237.1339111328125, 4.180911540985107421, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+167, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1831.5677490234375, -1114.2239990234375, -1244.13134765625, 4.972809791564941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+168, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1853.0355224609375, -1092.1658935546875, -1244.128173828125, 3.967277050018310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+169, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1847.362548828125, -1104.008056640625, -1244.1280517578125, 3.592915773391723632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+170, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1863.5260009765625, -1095.6024169921875, -1244.044677734375, 1.959525704383850097, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+171, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1859.49365234375, -1101.1512451171875, -1244.1280517578125, 5.406874656677246093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+172, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1842.4244384765625, -1115.927978515625, -1244.1280517578125, 2.451478481292724609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+173, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1923.0382080078125, -1022.98272705078125, -1237.1339111328125, 3.403586864471435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+174, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1924.9600830078125, -1028.2916259765625, -1237.1339111328125, 2.497084856033325195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+175, 220783, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1858.9271240234375, -1117.857666015625, -1244.044677734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Stalker (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+176, 223254, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1932.736083984375, -1024.4132080078125, -1233.9166259765625, 6.281504154205322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Queen Ansurek (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 434389 - [DNT] Holographic Emitter Projection, 448290 - [DNT] Ready to Sabotage)
(@CGUID+177, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1889.7586669921875, -1071.7447509765625, -1237.1339111328125, 1.483822226524353027, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+178, 220197, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1949.3350830078125, -924.125, -1244.13134765625, 5.975824356079101562, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Royal Swarmguard (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+179, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1812.0521240234375, -938.63543701171875, -1244.13134765625, 5.99766397476196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+180, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1927.3941650390625, -980.12152099609375, -1237.1339111328125, 0.594798922538757324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+181, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1939.017333984375, -920.7274169921875, -1244.13134765625, 5.753625392913818359, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+182, 220193, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1944.7899169921875, -932.6805419921875, -1244.13134765625, 0.265089988708496093, 7200, 0, 0, 0, NULL, 768, NULL, NULL, 56647), -- Sureki Venomblade (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+183, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1879.4774169921875, -901.703125, -1244.13134765625, 2.207658290863037109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+184, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1886.013916015625, -898.90277099609375, -1244.13134765625, 1.306725740432739257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+185, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1888.1666259765625, -986.4930419921875, -1237.1339111328125, 0.822538614273071289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+186, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1893.1614990234375, -902.87152099609375, -1244.13134765625, 1.196125745773315429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+187, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1916.154541015625, -921.99481201171875, -1244.13134765625, 3.404241561889648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+188, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1918.8802490234375, -928.66143798828125, -1244.13134765625, 2.735983610153198242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+189, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1904.166015625, -983.333984375, -1237.21728515625, 5.78829813003540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+190, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1910.7305908203125, -975.8038330078125, -1237.21728515625, 0.841170251369476318, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+191, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1900.0379638671875, -978.7005615234375, -1237.21728515625, 4.433457374572753906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+192, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1873.0850830078125, -895.86981201171875, -1244.13134765625, 1.829145312309265136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+193, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1873.329833984375, -901.28472900390625, -1244.13134765625, 1.906239032745361328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+194, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1899.59033203125, -988.38116455078125, -1237.21728515625, 0.734886646270751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+195, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1911.3243408203125, -988.74383544921875, -1237.21728515625, 6.034102439880371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+196, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1911.7447509765625, -928.31597900390625, -1244.13134765625, 2.751085758209228515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+197, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1910.0728759765625, -923.88714599609375, -1244.13134765625, 3.102092742919921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+198, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1928.7864990234375, -992.38543701171875, -1237.1339111328125, 5.376606941223144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+199, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1927.154541015625, -996.326416015625, -1237.1339111328125, 1.817517399787902832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+200, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1928.4097900390625, -1017.0625, -1237.1339111328125, 4.239866256713867187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+201, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1932.8992919921875, -1017.2274169921875, -1237.069580078125, 5.463269233703613281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+202, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1897.4947509765625, -1070.282958984375, -1237.1339111328125, 3.681783437728881835, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+203, 216649, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2216.55908203125, -1353.234375, -1207.4805908203125, 4.863024234771728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Vx (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 443055 - [DNT] Invisible, 447385 - Dual Wield, 443357 - Energy Controller)
(@CGUID+204, 216648, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2227.11279296875, -1358.4375, -1207.4805908203125, 5.710912227630615234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Nx (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 443055 - [DNT] Invisible, 443357 - Energy Controller)
(@CGUID+205, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1715.16845703125, -1189.326416015625, -1237.7547607421875, 3.487927198410034179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+206, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1719.7833251953125, -1138.51171875, -1237.9293212890625, 5.561587333679199218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@CGUID+207, 220199, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1722.1263427734375, -1144.6292724609375, -1237.9293212890625, 6.226707935333251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647); -- Battle Scarab (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+207;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+8, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Tes'ka
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Silkswooner Waree
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+40, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+77, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+88, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Visiting Merchant - 299698 - Permanent Feign Death
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+96, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Visiting Merchant - 299698 - Permanent Feign Death
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+99, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Visiting Merchant - 299698 - Permanent Feign Death
(@CGUID+101, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Visiting Merchant - 299698 - Permanent Feign Death
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+105, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+106, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+119, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+121, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+124, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+130, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+131, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+135, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+142, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+147, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+151, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+154, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+155, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+157, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Sureki Silkbinder
(@CGUID+159, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '18950'), -- Herald of Ansurek - 18950 - Invisibility and Stealth Detection
(@CGUID+164, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+166, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+177, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+181, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+182, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Sureki Venomblade
(@CGUID+202, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+205, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'); -- Umbral Citizen - 299698 - Permanent Feign Death

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+115;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 453634, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2864.286376953125, -253.817703247070312, -1189.6070556640625, 3.412121534347534179, 0, 0, -0.99086570739746093, 0.134852290153503417, 7200, 255, 1, 56647), -- Platform (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+1, 437052, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2780.735595703125, -336.07281494140625, -1165.562255859375, 0.767246484756469726, -0.19513893127441406, -0.07891654968261718, 0.365868568420410156, 0.906550109386444091, 7200, 255, 1, 56647), -- Web (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+2, 453116, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1726.60205078125, -763.53692626953125, -1243.2147216796875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+3, 449813, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1614.126953125, -784.619140625, -1335.943603515625, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+4, 449812, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1664.74462890625, -886.1612548828125, -1248.8873291015625, 3.226912975311279296, 0, 0, -0.99909019470214843, 0.042647112160921096, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+5, 449811, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1652.73046875, -785.481689453125, -1249.79248046875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+6, 453606, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1618.4305419921875, -754.16668701171875, -1337.5340576171875, 4.520405769348144531, 0, 0, -0.77162361145019531, 0.636079370975494384, 7200, 255, 1, 56647), -- Meeting Stone (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+7, 453600, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 453600 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+8, 453116, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1923.70849609375, -1048.8184814453125, -1236.6839599609375, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+9, 453602, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 453602 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+10, 453637, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1793.7066650390625, -814.47052001953125, -1249.501708984375, 1.27409064769744873, 0, 0, 0.594822883605957031, 0.80385679006576538, 7200, 255, 1, 56647), -- Forge (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+11, 465112, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 465112 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+12, 454132, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2118.064208984375, -1243.1822509765625, -1243.1268310546875, 1.134460687637329101, 0, 0, 0.537298202514648437, 0.84339231252670288, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+13, 454135, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2102.517333984375, -1165.8021240234375, -1243.8641357421875, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+14, 454134, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2002.814208984375, -1343.8472900390625, -1244.0059814453125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+15, 454129, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1943.63720703125, -1396.7899169921875, -1243.620361328125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+16, 454128, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1958.34033203125, -1310.640625, -1243.7113037109375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+17, 454130, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2173.65283203125, -1173.5382080078125, -1241.0123291015625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+18, 410287, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1711.251708984375, -834.703125, -1249.6024169921875, 0.779487669467926025, 0, 0, 0.37995147705078125, 0.925006449222564697, 7200, 255, 0, 56647), -- Shadecaster (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+19, 454122, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1784.0062255859375, -920.14501953125, -1242.2366943359375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+20, 466710, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 466710 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+21, 449812, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1744.1846923828125, -1210.53662109375, -1236.068603515625, 1.65610361099243164, 0, 0, 0.736615180969238281, 0.676312088966369628, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+22, 449813, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1659.0821533203125, -1115.8248291015625, -1237.669921875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+23, 455033, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 455033 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+24, 449812, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1940.322265625, -860.96783447265625, -1243.0224609375, 1.6648331880569458, 0, 0, 0.739560127258300781, 0.673090457916259765, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+25, 449811, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1688.89794921875, -1171.572998046875, -1237.4254150390625, 2.103119850158691406, 0, 0, 0.868198394775390625, 0.496217250823974609, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+26, 449811, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1689.2855224609375, -941.84906005859375, -1249.081787109375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+27, 454205, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 454205 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+28, 449812, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1939.3349609375, -980.45318603515625, -1235.9959716796875, 0.094034500420093536, 0, 0, 0.046999931335449218, 0.998894870281219482, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+29, 449811, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1774.478515625, -1179.5032958984375, -1237.135498046875, 0.523595929145812988, 0, 0, 0.258817672729492187, 0.965926229953765869, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+30, 449811, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1871.396484375, -1014.6297607421875, -1237.208740234375, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+31, 453689, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 453689 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+32, 453116, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1740.0931396484375, -1107.4774169921875, -1237.2274169921875, 5.035277843475341796, 0, 0, -0.58424854278564453, 0.811574757099151611, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+33, 453631, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 453631 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+34, 453605, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1800.4583740234375, -810.109375, -1249.501708984375, 4.476771354675292968, 0, 0, -0.78531646728515625, 0.619094550609588623, 7200, 255, 1, 56647), -- Anvil (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+35, 453651, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 453651 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+36, 453601, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 453601 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+37, 453663, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- 453663 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+38, 465113, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 465113 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+39, 453614, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 453614 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+40, 453609, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 453609 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+41, 453645, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 453645 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+42, 453644, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 453644 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+43, 453647, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 453647 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+44, 454133, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2137.329833984375, -1398.123291015625, -1236.92333984375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+45, 440997, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2168.666748046875, -1343.84033203125, -1207.4835205078125, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 7200, 255, 1, 56647), -- Web Barrier (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+46, 441260, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2263.270751953125, -1399.16845703125, -1207.483642578125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- Alliance Gate (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+47, 440999, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2168.302001953125, -1454.560791015625, -1207.4835205078125, 5.235990047454833984, 0, 0, -0.49999904632568359, 0.866025924682617187, 7200, 255, 1, 56647), -- Alliance Gate (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+48, 454131, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2062.56591796875, -1530.8228759765625, -1239.44189453125, 1.047199726104736328, 0, 0, 0.500000953674316406, 0.86602485179901123, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+49, 440998, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2136.72216796875, -1398.69970703125, -1207.4835205078125, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Alliance Gate (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+50, 441000, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2231.7900390625, -1344.1302490234375, -1207.48291015625, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 56647), -- Web Barrier (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+51, 438045, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2482.392578125, -1175.0770263671875, -1131.857177734375, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+52, 438047, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2648.23046875, -1204.9637451171875, -1131.857177734375, 5.497961997985839843, 0, 0, -0.38260269165039062, 0.92391294240951538, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+53, 438046, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2648.26220703125, -1145.0802001953125, -1131.857177734375, 3.926820993423461914, 0, 0, -0.92391204833984375, 0.382604897022247314, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+54, 445075, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2993.99755859375, -122.765625, -1138.4207763671875, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 0, 56647), -- Web Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+55, 466709, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 466709 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+56, 466708, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 466708 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+57, 466711, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 466711 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+58, 455031, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 455031 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+59, 455030, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 455030 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+60, 455032, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 455032 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+61, 449810, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2370.33935546875, -1679.9903564453125, -1168.0537109375, 0.94247448444366455, 0, 0, 0.453989028930664062, 0.89100724458694458, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+62, 444355, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2719.962646484375, -396.542388916015625, -1158.6959228515625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+63, 449810, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2581.024169921875, -1300.4906005859375, -899.906494140625, 0, 0, 0, 0, 1, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+64, 454204, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 454204 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+65, 454206, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 454206 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+66, 454203, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 454203 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+67, 453687, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 453687 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+68, 449810, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2220.59033203125, -1684.2547607421875, -1188.3804931640625, 2.085664033889770507, 0, 0, 0.863834381103515625, 0.50377589464187622, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+69, 453688, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 453688 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+70, 449810, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1067.8953857421875, -1467.1839599609375, -1260.17236328125, 0.872668087482452392, 0, 0, 0.422619819641113281, 0.906307041645050048, 7200, 255, 0, 56647), -- Door (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+71, 453690, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 453690 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+72, 453622, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 453622 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+73, 453654, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 453654 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+74, 453649, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 453649 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+75, 465111, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- 465111 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+76, 465110, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- 465110 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+77, 453607, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- 453607 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+78, 410287, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1757.74658203125, -999.388916015625, -1243.0941162109375, 5.959412097930908203, 0, 0, -0.16118049621582031, 0.986924946308135986, 7200, 255, 0, 56647), -- Shadecaster (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+79, 453668, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1757.685791015625, -999.2569580078125, -1243.15625, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 7200, 255, 1, 56647), -- 11Z5_Nerubian_Rug (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+80, 410287, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1932.6649169921875, -1024.41845703125, -1237.21728515625, 6.281505107879638671, 0, 0, -0.0008401870727539, 0.999999642372131347, 7200, 255, 0, 56647), -- Shadecaster (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+81, 463913, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1944.6304931640625, -1089.746337890625, -1241.0877685546875, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 7200, 255, 1, 56647), -- 11NB_Nerubian_Market_Counter03 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+82, 410287, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1668.421875, -1150.75, -1238.4476318359375, 1.687795639038085937, 0, 0, 0.747239112854003906, 0.664555251598358154, 7200, 255, 0, 56647), -- Shadecaster (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+83, 453921, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1950.3939208984375, -1292.349365234375, -1244.177490234375, 4.895322322845458984, 0, 0, -0.63956451416015625, 0.768737435340881347, 7200, 255, 1, 56647), -- Chair (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+84, 463864, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1944.8074951171875, -1313.0308837890625, -1244.030029296875, 1.84099280834197998, 0, 0, 0.795902252197265625, 0.605425119400024414, 7200, 255, 1, 56647), -- 11NB_Nerubian_Table03 (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+85, 453642, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2057.93408203125, -1116.3524169921875, -1276.9166259765625, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 7200, 255, 1, 56647), -- Chair (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+86, 453612, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2072.288330078125, -1267.388916015625, -1244.1900634765625, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 7200, 255, 1, 56647), -- Anvil (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+87, 453646, 2669, 14979, 15111, '1,2,8,23', 0, 0, -2062.2587890625, -1272.05908203125, -1244.5191650390625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 56647), -- Forge (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+88, 453652, 2669, 14979, 15111, '1,2,8,23', 0, 0, -1988.1475830078125, -1369.545166015625, -1244.185302734375, 0.54977881908416748, 0, 0, 0.271440505981445312, 0.962455213069915771, 7200, 255, 1, 56647), -- Chair (Area: Umbral Bazaar - Difficulty: Normal) CreateObject1
(@OGUID+89, 453617, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2112.55908203125, -1272.171875, -1219.244384765625, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+90, 453628, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2115.1181640625, -1270.5625, -1219.21923828125, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+91, 453667, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2111.626708984375, -1265.23095703125, -1219.1392822265625, 4.075345039367675781, 0, 0, -0.89297866821289062, 0.450098991394042968, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+92, 453593, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2108.998291015625, -1266.6441650390625, -1219.1392822265625, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+93, 453610, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+94, 453596, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+95, 453653, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2128.979248046875, -1254.4879150390625, -1219.1396484375, 4.162615776062011718, 0, 0, -0.87249469757080078, 0.488623589277267456, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+96, 453662, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2126.17529296875, -1255.970458984375, -1219.1396484375, 3.708826541900634765, 0, 0, -0.96004962921142578, 0.279829770326614379, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+97, 453621, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+98, 453666, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+99, 453650, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2132.795166015625, -1260.5242919921875, -1219.242431640625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+100, 453633, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2129.798583984375, -1262.0103759765625, -1219.2447509765625, 1.352629423141479492, 0, 0, 0.62592315673828125, 0.779884755611419677, 7200, 255, 1, 56647), -- Chair (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+101, 451879, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2073.70654296875, -1406.1285400390625, -1237.6441650390625, 5.820998668670654296, 0, 0, -0.22904205322265625, 0.973416507244110107, 7200, 255, 1, 56647), -- 11NP_Nerubian_Food_Feast_02 (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+102, 451879, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2074.357666015625, -1423.9913330078125, -1237.529052734375, 0.406572580337524414, 0, 0, 0.2018890380859375, 0.9794083833694458, 7200, 255, 1, 56647), -- 11NP_Nerubian_Food_Feast_02 (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+103, 445076, 2669, 14979, 15112, '1,2,8,23', 0, 0, -3182.06640625, 65.30352783203125, -1136.87890625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 56647), -- Web Door (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+104, 453603, 2669, 14979, 15112, '1,2,8,23', 0, 0, -2171.0400390625, -1040.982666015625, -1325.1141357421875, 3.23760390281677246, 0, 0, -0.99884796142578125, 0.047987140715122222, 7200, 255, 1, 56647), -- Anvil (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+105, 445024, 2669, 14979, 15112, '1,2,8,23', 0, 0, -3263.970947265625, 145.64996337890625, -1091.687255859375, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 56647), -- Door (Area: High Hollows - Difficulty: Normal) CreateObject1
(@OGUID+106, 453625, 2669, 14979, 15113, '1,2,8,23', 0, 0, -2666.75, -1174.9600830078125, -1084.0723876953125, 3.161077022552490234, 0.180260658264160156, -0.00292682647705078, -0.98357582092285156, 0.008724398910999298, 7200, 255, 1, 56647), -- Air Duct (Area: The Transformatory - Difficulty: Normal) CreateObject1
(@OGUID+107, 443865, 2669, 14979, 15113, '1,2,8,23', 0, 0, -3439.154541015625, 257.05804443359375, -1090.74755859375, 6.206033229827880859, 0, 0, -0.03856658935546875, 0.999256014823913574, 7200, 255, 1, 56647), -- Door (Area: The Transformatory - Difficulty: Normal) CreateObject1
(@OGUID+108, 443864, 2669, 14979, 15113, '1,2,8,23', 0, 0, -3374.10205078125, 323.00872802734375, -1090.61572265625, 4.803981304168701171, 0, 0, -0.67399406433105468, 0.738736748695373535, 7200, 255, 1, 56647), -- Door (Area: The Transformatory - Difficulty: Normal) CreateObject1
(@OGUID+109, 452122, 2669, 14979, 15113, '1,2,8,23', 0, 0, -3608.3974609375, 197.63330078125, -1112.198974609375, 5.78893136978149414, 0, 0, -0.24461936950683593, 0.969619154930114746, 7200, 255, 0, 56647), -- Barrier (Area: The Transformatory - Difficulty: Normal) CreateObject1
(@OGUID+110, 463864, 2669, 14979, 0, '1,2,8,23', 0, 0, -2842.08984375, -1087.8939208984375, -1106.4349365234375, 5.043671607971191406, 0, 0, -0.58083724975585937, 0.814019680023193359, 7200, 255, 1, 56647), -- 11NB_Nerubian_Table03 (Area: 0 - Difficulty: Normal) CreateObject1
(@OGUID+111, 444012, 2669, 14979, 0, '1,2,8,23', 0, 0, -3381.858642578125, 355.76904296875, -1061.8153076171875, 4.72756195068359375, 0, 0, -0.7017221450805664, 0.712450683116912841, 7200, 255, 1, 56647), -- Door (Area: 0 - Difficulty: Normal) CreateObject1
(@OGUID+112, 444011, 2669, 14979, 0, '1,2,8,23', 0, 0, -3447.842041015625, 329.31915283203125, -1059.646484375, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 56647), -- Door (Area: 0 - Difficulty: Normal) CreateObject1
(@OGUID+113, 453921, 2669, 14979, 0, '1,2,8,23', 0, 0, -2835.251220703125, -1108.19580078125, -1106.5823974609375, 1.814810395240783691, 0, 0, 0.787908554077148437, 0.615792274475097656, 7200, 255, 1, 56647), -- Chair (Area: 0 - Difficulty: Normal) CreateObject1
(@OGUID+114, 453053, 2669, 14979, 0, '1,2,8,23', 0, 0, -2801.882080078125, -1031.78515625, -1136.12158203125, 2.76633763313293457, 0, 0, 0.982449531555175781, 0.186528548598289489, 7200, 255, 1, 56647), -- Chair (Area: 0 - Difficulty: Normal) CreateObject1
(@OGUID+115, 454747, 2669, 14979, 0, '1,2,8,23', 0, 0, -3450.509765625, 333.5712890625, -1054.9351806640625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 0, 56647); -- 11DU_NerubianRaid_Special_WebWall01 (Area: 0 - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+115;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 0), -- Platform
(@OGUID+1, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Web
(@OGUID+2, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Door
(@OGUID+3, 0, 0, 0.953716933727264404, 0.300705939531326293, 0, 0), -- Door
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+5, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Door
(@OGUID+8, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Door
(@OGUID+19, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Door
(@OGUID+21, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0), -- Door
(@OGUID+22, 0, 0, 0.965925753116607666, 0.258819460868835449, 0, 0), -- Door
(@OGUID+24, 0, 0, 0.710186660289764404, 0.704013407230377197, 0, 0), -- Door
(@OGUID+25, 0, 0, 0.868198752403259277, 0.496216654777526855, 0, 0), -- Door
(@OGUID+26, 0, 0, 0.70710688829421997, 0.707106649875640869, 0, 0), -- Door
(@OGUID+28, 0, 0, 0.004363371990621089, 0.999990463256835937, 0, 0), -- Door
(@OGUID+29, 0, 0, 0.258818358182907104, 0.965926051139831542, 0, 0), -- Door
(@OGUID+30, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Door
(@OGUID+32, 0, 0, -0.58424925804138183, 0.811574339866638183, 0, 0), -- Door
(@OGUID+51, 0, 0, 0.000000325841369885, 1, 0, 0), -- Door
(@OGUID+52, 0, 0, 0.000000325841369885, 1, 0, 0), -- Door
(@OGUID+53, 0, 0, 0.000000325841369885, 1, 0, 0), -- Door
(@OGUID+54, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Web Door
(@OGUID+61, 0, 0, 0.453989654779434204, 0.891006946563720703, 0, 0), -- Door
(@OGUID+62, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Door
(@OGUID+63, 0, 0, 0.000000325841369885, 1, 0, 0), -- Door
(@OGUID+68, 0, 0, 0.863834738731384277, 0.503775298595428466, 0, 0), -- Door
(@OGUID+70, 0, 0, 0.422620654106140136, 0.906306684017181396, 0, 0), -- Door
(@OGUID+81, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- 11NB_Nerubian_Market_Counter03
(@OGUID+83, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+84, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- 11NB_Nerubian_Table03
(@OGUID+103, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Web Door
(@OGUID+105, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Door
(@OGUID+107, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Door
(@OGUID+108, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Door
(@OGUID+109, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Barrier
(@OGUID+110, 0, 0, 0.410718053579330444, 0.911762416362762451, 0, 0), -- 11NB_Nerubian_Table03
(@OGUID+111, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Door
(@OGUID+112, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0), -- Door
(@OGUID+113, 0, 0, 0.410718053579330444, 0.911762416362762451, 0, 0), -- Chair
(@OGUID+114, 0, 0, -0.25881913304328918, 0.965925812721252441, 0, 0), -- Chair
(@OGUID+115, 0, 0, -0.38268372416496276, 0.923879444599151611, 0, 0); -- 11DU_NerubianRaid_Special_WebWall01

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=35803 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(35803, 0, 0, 56647);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=@ATPROPERTIESID+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, 35803, 0, 0, 0, 0, 0, 0, -1, 0, 0, 449122, 0, 0, 0, 20, 20, 0, 0, 0, 0, 0, 0, 56647);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 2669, '1,2,8,23', -1897.5572509765625, -1156.79345703125, -1243.6788330078125, 0.773980677127838134, 0, 0, 0, 'City of Threads - Orator Krixvizk Bridge Barrier', 56647); -- 449122 ([DNT] Knockback) (Area: Umbral Bazaar - Difficulty: Normal)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (216648 /*216648 (Nx) - [DNT] Invisible, Energy Controller*/, 216649 /*216649 (Vx) - [DNT] Invisible, Dual Wield, Energy Controller*/, 225962 /*225962 (Path Helper) - Advert*/, 220777 /*220777 (Executor Nizrek) - Bot AI Follow Advert*/, 220431 /*220431 (Visiting Merchant) - Permanent Feign Death*/, 224329 /*224329 (Visiting Merchant) - Permanent Feign Death*/, 220479 /*220479 (Visiting Merchant) - Permanent Feign Death*/, 204401 /*204401 (Stalker)*/, 220351 /*220351 (Umbral Citizen) - Permanent Feign Death*/, 220196 /*220196 (Herald of Ansurek) - Invisibility and Stealth Detection*/, 223254 /*223254 (Queen Ansurek) - [DNT] Holographic Emitter Projection, [DNT] Ready to Sabotage*/, 220782 /*220782 (Stalker)*/, 224324 /*224324 (Silkswooner Waree)*/, 220197 /*220197 (Royal Swarmguard) - Invisibility and Stealth Detection*/, 216619 /*216619 (Orator Krix'vizk) - Oration, Bot AI Follow Advert*/, 220353 /*220353 (Umbral Citizen) - Permanent Feign Death*/, 220195 /*220195 (Sureki Silkbinder)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(216648, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '443055 443357'), -- 216648 (Nx) - [DNT] Invisible, Energy Controller
(216649, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '443055 447385 443357'), -- 216649 (Vx) - [DNT] Invisible, Dual Wield, Energy Controller
(225962, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '454706'), -- 225962 (Path Helper) - Advert
(220777, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '422359'), -- 220777 (Executor Nizrek) - Bot AI Follow Advert
(220431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220431 (Visiting Merchant)
(224329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 224329 (Visiting Merchant)
(220479, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220479 (Visiting Merchant)
(204401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 204401 (Stalker)
(220351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220351 (Umbral Citizen) - Permanent Feign Death
(220196, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 220196 (Herald of Ansurek) - Invisibility and Stealth Detection
(223254, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '434389 448290'), -- 223254 (Queen Ansurek) - [DNT] Holographic Emitter Projection, [DNT] Ready to Sabotage
(220782, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 220782 (Stalker)
(224324, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 224324 (Silkswooner Waree)
(220197, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 220197 (Royal Swarmguard) - Invisibility and Stealth Detection
(216619, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '454689 422356'), -- 216619 (Orator Krix'vizk) - Oration, Bot AI Follow Advert
(220353, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220353 (Umbral Citizen) - Permanent Feign Death
(220195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 220195 (Sureki Silkbinder)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (453813 /*453813*/, 466715 /*466715*/, 466718 /*466718*/, 466716 /*466716*/, 466717 /*466717*/, 455631 /*455631*/, 452015 /*452015*/, 453779 /*453779*/, 456234 /*456234*/, 456235 /*456235*/, 453782 /*453782*/, 349097 /*Instance Portal*/, 453780 /*453780*/, 413883 /*Crystallized Bismuth*/, 453781 /*453781*/, 456236 /*456236*/, 456237 /*456237*/, 455634 /*455634*/, 455632 /*455632*/, 454472 /*Pulley*/, 455633 /*455633*/, 452018 /*452018*/, 452016 /*452016*/, 452506 /*452506*/, 452504 /*452504*/, 452505 /*452505*/, 455731 /*455731*/, 452846 /*452846*/, 452503 /*452503*/, 452847 /*452847*/, 452844 /*452844*/, 455734 /*455734*/, 452845 /*452845*/, 455732 /*455732*/, 455733 /*455733*/, 433643 /*Cleanse Horrific Poison (DNT)*/, 453192 /*453192*/, 456088 /*456088*/, 453573 /*Platform*/, 453190 /*453190*/, 456089 /*456089*/, 453191 /*453191*/, 453189 /*453189*/, 422531 /*Disturbed Earth*/, 434501 /*Door*/, 456086 /*456086*/, 410834 /*Catalogue of Cagables*/, 456087 /*456087*/, 442692 /*Propaganda Hologram*/, 465098 /*465098*/, 465099 /*465099*/, 465097 /*465097*/, 465100 /*465100*/, 453816 /*453816*/, 453814 /*453814*/, 453815 /*453815*/, 453625 /*Air Duct*/, 453668 /*11Z5_Nerubian_Rug*/, 453607 /*453607*/, 465110 /*465110*/, 465111 /*465111*/, 453649 /*453649*/, 453654 /*453654*/, 453622 /*453622*/, 453690 /*453690*/, 453688 /*453688*/, 453687 /*453687*/, 454203 /*454203*/, 454206 /*454206*/, 454204 /*454204*/, 455032 /*455032*/, 455030 /*455030*/, 455031 /*455031*/, 466711 /*466711*/, 466708 /*466708*/, 466709 /*466709*/, 441000 /*Web Barrier*/, 440998 /*Alliance Gate*/, 454131 /*Door*/, 440999 /*Alliance Gate*/, 441260 /*Alliance Gate*/, 440997 /*Web Barrier*/, 454133 /*Door*/, 453647 /*453647*/, 453644 /*453644*/, 453645 /*453645*/, 453609 /*453609*/, 453614 /*453614*/, 465113 /*465113*/, 453663 /*453663*/, 453601 /*453601*/, 453651 /*453651*/, 453631 /*453631*/, 453689 /*453689*/, 454205 /*454205*/, 455033 /*455033*/, 466710 /*466710*/, 454122 /*Door*/, 410287 /*Shadecaster*/, 454130 /*Door*/, 454128 /*Door*/, 454129 /*Door*/, 454134 /*Door*/, 454135 /*Door*/, 454132 /*Door*/, 465112 /*465112*/, 453602 /*453602*/, 453600 /*453600*/, 449811 /*Door*/, 449812 /*Door*/, 449813 /*Door*/, 453116 /*Door*/, 453634 /*Platform*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(453813, 0, 32, 0, 0), -- 453813
(466715, 0, 32, 0, 0), -- 466715
(466718, 0, 32, 0, 0), -- 466718
(466716, 0, 32, 0, 0), -- 466716
(466717, 0, 32, 0, 0), -- 466717
(455631, 0, 32, 0, 0), -- 455631
(452015, 0, 32, 0, 0), -- 452015
(453779, 0, 32, 0, 0), -- 453779
(456234, 0, 32, 0, 0), -- 456234
(456235, 0, 32, 0, 0), -- 456235
(453782, 0, 32, 0, 0), -- 453782
(349097, 0, 32, 0, 0), -- Instance Portal
(453780, 0, 32, 0, 0), -- 453780
(413883, 94, 278528, 0, 0), -- Crystallized Bismuth
(453781, 0, 32, 0, 0), -- 453781
(456236, 0, 32, 0, 0), -- 456236
(456237, 0, 32, 0, 0), -- 456237
(455634, 0, 32, 0, 0), -- 455634
(455632, 0, 32, 0, 0), -- 455632
(454472, 0, 32, 0, 0), -- Pulley
(455633, 0, 32, 0, 0), -- 455633
(452018, 0, 32, 0, 0), -- 452018
(452016, 0, 32, 0, 0), -- 452016
(452506, 0, 32, 0, 0), -- 452506
(452504, 0, 32, 0, 0), -- 452504
(452505, 0, 32, 0, 0), -- 452505
(455731, 0, 32, 0, 0), -- 455731
(452846, 0, 32, 0, 0), -- 452846
(452503, 0, 32, 0, 0), -- 452503
(452847, 0, 32, 0, 0), -- 452847
(452844, 0, 32, 0, 0), -- 452844
(455734, 0, 32, 0, 0), -- 455734
(452845, 0, 32, 0, 0), -- 452845
(455732, 0, 32, 0, 0), -- 455732
(455733, 0, 32, 0, 0), -- 455733
(433643, 168, 0, 0, 0), -- Cleanse Horrific Poison (DNT)
(453192, 0, 32, 0, 0), -- 453192
(456088, 0, 32, 0, 0), -- 456088
(453573, 0, 1048624, 0, 0), -- Platform
(453190, 0, 32, 0, 0), -- 453190
(456089, 0, 32, 0, 0), -- 456089
(453191, 0, 32, 0, 0), -- 453191
(453189, 0, 32, 0, 0), -- 453189
(422531, 0, 0, 3710, 0), -- Disturbed Earth
(434501, 0, 48, 0, 0), -- Door
(456086, 0, 32, 0, 0), -- 456086
(410834, 0, 262144, 0, 0), -- Catalogue of Cagables
(456087, 0, 32, 0, 0), -- 456087
(442692, 0, 262144, 0, 0), -- Propaganda Hologram
(465098, 0, 32, 0, 0), -- 465098
(465099, 0, 32, 0, 0), -- 465099
(465097, 0, 32, 0, 0), -- 465097
(465100, 0, 32, 0, 0), -- 465100
(453816, 0, 32, 0, 0), -- 453816
(453814, 0, 32, 0, 0), -- 453814
(453815, 0, 32, 0, 0), -- 453815
(453625, 0, 262144, 0, 0), -- Air Duct
(453668, 0, 16, 0, 0), -- 11Z5_Nerubian_Rug
(453607, 0, 32, 0, 0), -- 453607
(465110, 0, 32, 0, 0), -- 465110
(465111, 0, 32, 0, 0), -- 465111
(453649, 0, 32, 0, 0), -- 453649
(453654, 0, 32, 0, 0), -- 453654
(453622, 0, 32, 0, 0), -- 453622
(453690, 0, 32, 0, 0), -- 453690
(453688, 0, 32, 0, 0), -- 453688
(453687, 0, 32, 0, 0), -- 453687
(454203, 0, 32, 0, 0), -- 454203
(454206, 0, 32, 0, 0), -- 454206
(454204, 0, 32, 0, 0), -- 454204
(455032, 0, 32, 0, 0), -- 455032
(455030, 0, 32, 0, 0), -- 455030
(455031, 0, 32, 0, 0), -- 455031
(466711, 0, 32, 0, 0), -- 466711
(466708, 0, 32, 0, 0), -- 466708
(466709, 0, 32, 0, 0), -- 466709
(441000, 114, 48, 0, 0), -- Web Barrier
(440998, 114, 32, 0, 0), -- Alliance Gate
(454131, 0, 48, 0, 0), -- Door
(440999, 114, 32, 0, 0), -- Alliance Gate
(441260, 114, 32, 0, 0), -- Alliance Gate
(440997, 114, 48, 0, 0), -- Web Barrier
(454133, 0, 32, 0, 0), -- Door
(453647, 0, 32, 0, 0), -- 453647
(453644, 0, 32, 0, 0), -- 453644
(453645, 0, 32, 0, 0), -- 453645
(453609, 0, 32, 0, 0), -- 453609
(453614, 0, 32, 0, 0), -- 453614
(465113, 0, 32, 0, 0), -- 465113
(453663, 0, 32, 0, 0), -- 453663
(453601, 0, 32, 0, 0), -- 453601
(453651, 0, 32, 0, 0), -- 453651
(453631, 0, 32, 0, 0), -- 453631
(453689, 0, 32, 0, 0), -- 453689
(454205, 0, 32, 0, 0), -- 454205
(455033, 0, 32, 0, 0), -- 455033
(466710, 0, 32, 0, 0), -- 466710
(454122, 0, 50, 0, 0), -- Door
(410287, 0, 67371008, 0, 0), -- Shadecaster
(454130, 0, 48, 0, 0), -- Door
(454128, 0, 32, 0, 0), -- Door
(454129, 0, 48, 0, 0), -- Door
(454134, 0, 32, 0, 0), -- Door
(454135, 0, 32, 0, 0), -- Door
(454132, 0, 32, 0, 0), -- Door
(465112, 0, 32, 0, 0), -- 465112
(453602, 0, 32, 0, 0), -- 453602
(453600, 0, 32, 0, 0), -- 453600
(449811, 0, 50, 0, 0), -- Door
(449812, 0, 50, 0, 0), -- Door
(449813, 0, 50, 0, 0), -- Door
(453116, 0, 48, 0, 0), -- Door
(453634, 0, 1048624, 0, 0); -- Platform

-- Template
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=2.571428537368774414, `BaseAttackTime`=1500, `unit_flags`=33554752 WHERE `entry`=216648; -- Nx
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=2.571428537368774414, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=8388608 WHERE `entry`=216649; -- Vx
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1073741825, `flags_extra` = 128 WHERE `entry` IN (220783, 204401, 220782); -- Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=225962; -- Path Helper
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048 WHERE `entry`=220777; -- Executor Nizrek
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry` IN (220431, 224329); -- Visiting Merchant
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777217 WHERE `entry`=220479; -- Visiting Merchant
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224331; -- Phylleus
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224330; -- Maraclozh
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220196; -- Herald of Ansurek
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=8960, `unit_flags2`=2048, `unit_flags3`=1073741824 WHERE `entry`=223254; -- Queen Ansurek
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224324; -- Silkswooner Waree
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220197; -- Royal Swarmguard
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=216619; -- Orator Krix'vizk
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224327; -- Violesca
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224320; -- Tes'ka
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224321; -- Ves'ka
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry` IN (220353, 220351); -- Umbral Citizen
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220193; -- Sureki Venomblade
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=220199; -- Battle Scarab
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220195; -- Sureki Silkbinder

DELETE FROM `gameobject_template` WHERE `entry` IN (442692 /*Propaganda Hologram*/, 453625 /*Air Duct*/, 453603 /*Anvil*/, 453666 /*Chair*/, 453650 /*Chair*/, 453633 /*Chair*/, 453621 /*Chair*/, 453662 /*Chair*/, 453653 /*Chair*/, 453610 /*Chair*/, 453596 /*Chair*/, 453667 /*Chair*/, 453628 /*Chair*/, 453617 /*Chair*/, 453593 /*Chair*/, 453652 /*Chair*/, 453646 /*Forge*/, 453612 /*Anvil*/, 453642 /*Chair*/, 453668 /*11Z5_Nerubian_Rug*/, 441000 /*Web Barrier*/, 454133 /*Door*/, 441260 /*Alliance Gate*/, 440998 /*Alliance Gate*/, 454131 /*Door*/, 440999 /*Alliance Gate*/, 466711 /*466711*/, 466709 /*466709*/, 466708 /*466708*/, 465113 /*465113*/, 465111 /*465111*/, 465110 /*465110*/, 455032 /*455032*/, 455031 /*455031*/, 455030 /*455030*/, 454206 /*454206*/, 454204 /*454204*/, 454203 /*454203*/, 453690 /*453690*/, 453688 /*453688*/, 453687 /*453687*/, 453654 /*453654*/, 453649 /*453649*/, 453647 /*453647*/, 453645 /*453645*/, 453644 /*453644*/, 453622 /*453622*/, 453614 /*453614*/, 453609 /*453609*/, 453607 /*453607*/, 440997 /*Web Barrier*/, 453651 /*453651*/, 453601 /*453601*/, 453600 /*453600*/, 454205 /*454205*/, 453689 /*453689*/, 465112 /*465112*/, 453602 /*453602*/, 453663 /*453663*/, 453631 /*453631*/, 466710 /*466710*/, 455033 /*455033*/, 454129 /*Door*/, 454130 /*Door*/, 454132 /*Door*/, 454134 /*Door*/, 454128 /*Door*/, 454135 /*Door*/, 453605 /*Anvil*/, 454122 /*Door*/, 453637 /*Forge*/, 453116 /*Door*/, 453606 /*Meeting Stone*/, 449812 /*Door*/, 449813 /*Door*/, 449811 /*Door*/, 453634 /*Platform*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(442692, 10, 87030, 'Propaganda Hologram', 'questinteract', '', '', 1, 3601, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2762, 56647), -- Propaganda Hologram
(453625, 10, 88767, 'Air Duct', 'questinteract', '', '', 1, 3757, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 439845, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 120394, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Air Duct
(453603, 8, 92405, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 103828, 0, 30091, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Anvil
(453666, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453650, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453633, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453621, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453662, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453653, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453610, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453596, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453667, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453628, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453617, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453593, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453652, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453646, 8, 92400, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 103829, 0, 30092, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Forge
(453612, 8, 92405, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 103828, 0, 30091, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Anvil
(453642, 7, 89574, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Chair
(453668, 5, 87770, '11Z5_Nerubian_Rug', '', '', '', 0.911199986934661865, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11Z5_Nerubian_Rug
(441000, 0, 90149, 'Web Barrier', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Web Barrier
(454133, 0, 90341, 'Door', '', '', '', 0.779999971389770507, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(441260, 0, 90149, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Alliance Gate
(440998, 0, 90149, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Alliance Gate
(454131, 0, 85068, 'Door', '', '', '', 1, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(440999, 0, 90149, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Alliance Gate
(466711, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 466711
(466709, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 466709
(466708, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 466708
(465113, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 465113
(465111, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 465111
(465110, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 465110
(455032, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 455032
(455031, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 455031
(455030, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 455030
(454206, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 454206
(454204, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 454204
(454203, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 454203
(453690, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453690
(453688, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453688
(453687, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453687
(453654, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453654
(453649, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453649
(453647, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453647
(453645, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453645
(453644, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453644
(453622, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453622
(453614, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453614
(453609, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453609
(453607, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453607
(440997, 0, 90149, 'Web Barrier', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Web Barrier
(453651, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453651
(453601, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453601
(453600, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453600
(454205, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 454205
(453689, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453689
(465112, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 465112
(453602, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453602
(453663, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453663
(453631, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 453631
(466710, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 466710
(455033, 0, 89574, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 455033
(454129, 0, 85068, 'Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(454130, 0, 85068, 'Door', '', '', '', 1.619999885559082031, 1, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(454132, 0, 85068, 'Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(454134, 0, 85068, 'Door', '', '', '', 1, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(454128, 0, 85068, 'Door', '', '', '', 1, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(454135, 0, 85068, 'Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(453605, 8, 92405, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 103828, 0, 30091, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Anvil
(454122, 0, 85068, 'Door', '', '', '', 1.631624221801757812, 0, 920, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(453637, 8, 92400, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 103829, 0, 30092, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Forge
(453116, 0, 85068, 'Door', '', '', '', 0.999999523162841796, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(453606, 23, 92048, 'Meeting Stone', '', '', '', 1, 1, 60, 15111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2974, 56647), -- Meeting Stone
(449812, 0, 85068, 'Door', '', '', '', 0.999999523162841796, 0, 920, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(449813, 0, 85068, 'Door', '', '', '', 0.999999523162841796, 0, 920, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(449811, 0, 85068, 'Door', '', '', '', 0.999999523162841796, 0, 920, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Door
(453634, 33, 87662, 'Platform', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 379, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647); -- Platform

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (224732,228361,224731,223357,223844,223181,223182,220037,230047,226053,230056,224756,216648,216649,224330,220193)) OR (`ID`=11 AND `CreatureID`=76168);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(224732, 1, 222911, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Covert Webmancer
(228361, 1, 214501, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Agile Pursuer
(224731, 1, 222912, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Web Marauder
(223357, 1, 214503, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Sureki Conscript
(223844, 1, 222911, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Covert Webmancer
(223181, 1, 214501, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Agile Pursuer
(223182, 1, 222912, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Web Marauder
(220037, 1, 214500, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Reposing Knight
(230047, 1, 222912, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Q'ilax
(226053, 1, 2200, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Assistant Ulo'vix
(230056, 1, 214501, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Assistant Ven'ik
(224756, 1, 224299, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Boulderbane
(216648, 1, 202248, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Nx
(216649, 1, 51815, 0, 0, 51815, 0, 0, 0, 0, 0, 56647), -- Vx
(224330, 1, 104200, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Maraclozh
(76168, 11, 188349, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Ravager
(220193, 1, 221767, 0, 0, 0, 0, 0, 0, 0, 0, 56647); -- Sureki Venomblade

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=223254 AND `MenuID`=34880);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(223254, 34880, 56819); -- Queen Ansurek

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 263483, 0, 0, 0, 0, 0, 0, 0, 56819); -- 223254 (Queen Ansurek)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34880 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34880, @NPCTEXTID+0, 56819); -- 223254 (Queen Ansurek)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=34880 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34880, 122351, 0, 0, '<Sabotage the device and steal some of its power.>\n[Requires Rogue, Priest, or at least 25 skill in Khaz Algar Engineering.]|r', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56819);

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` = 299698;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(299698, 'spell_gen_feign_death_all_flags');

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (119872, 123280, 118826, 118827, 120893, 120896, 120892, 120891, 123419, 120894, 117254, 120895, 120919, 120897, 116499, 120890, 120887, 120886, 120888, 120889, 116701, 119370, 119369, 119374, 114414, 119376, 119375, 118106, 119371, 119377, 119379, 120885, 119732, 121817, 123418, 116699, 116700, 120907, 120905, 120882, 120872, 120884, 120908, 116692, 120881, 120874, 120869, 120883, 120906, 120871, 120870, 120873, 120589, 120875, 120868);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(119872, 1.411402583122253417, 1.379999995231628417, 0, 56647),
(123280, 2, 0, 0, 56647),
(118826, 0.5, 10, 0, 56647),
(118827, 2.454613208770751953, 2.40000009536743164, 0, 56647),
(120893, 1.043526291847229003, 1, 0, 56647),
(120896, 1.565289497375488281, 1.5, 0, 56647),
(120892, 1.043526291847229003, 1, 0, 56647),
(120891, 1.043526291847229003, 1, 0, 56647),
(123419, 0.347000002861022949, 1.5, 0, 56647),
(120894, 1.565289497375488281, 1.5, 0, 56647),
(117254, 3.90488433837890625, 6, 0, 56647),
(120895, 1.565289497375488281, 1.5, 0, 56647),
(120919, 1, 0, 0, 56647),
(120897, 1.565289497375488281, 1.5, 0, 56647),
(116499, 5.900434017181396484, 3.5, 0, 56647),
(120890, 0.60000002384185791, 12.0000009536743164, 0, 56647),
(120887, 2.540548324584960937, 2, 0, 56647),
(120886, 2.540548324584960937, 2, 0, 56647),
(120888, 2.540548324584960937, 2, 0, 56647),
(120889, 2.540548324584960937, 2, 0, 56647),
(116701, 0.790720283985137939, 1.5, 0, 56647),
(119370, 0.948864400386810302, 1.80000007152557373, 0, 56647),
(119369, 0.948864400386810302, 1.80000007152557373, 0, 56647),
(119374, 1.186080455780029296, 2.25, 0, 56647),
(114414, 1.534133195877075195, 1.5, 0, 56647),
(119376, 1.186080455780029296, 2.25, 0, 56647),
(119375, 1.186080455780029296, 2.25, 0, 56647),
(118106, 0.948864459991455078, 1.800000190734863281, 0, 56647),
(119371, 0.948864340782165527, 1.80000007152557373, 0, 56647),
(119377, 1.186080455780029296, 2.25, 0, 56647),
(119379, 1.186080455780029296, 2.25, 0, 56647),
(120885, 0.375, 7.5, 0, 56647),
(119732, 1.472768068313598632, 1.440000057220458984, 0, 56647),
(121817, 0.948864400386810302, 1.80000007152557373, 0, 56647),
(123418, 0.347000002861022949, 1.5, 0, 56647),
(116699, 0.790720283985137939, 1.5, 0, 56647),
(116700, 0.790720283985137939, 1.5, 0, 56647),
(120907, 1.534133076667785644, 1.499999880790710449, 0, 56647),
(120905, 1.534133076667785644, 1.499999880790710449, 0, 56647),
(120882, 0.5, 10, 0, 56647),
(120872, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120884, 0.5, 10, 0, 56647),
(120908, 1.534133076667785644, 1.499999880790710449, 0, 56647),
(116692, 1.227306604385375976, 1.20000004768371582, 0, 56647),
(120881, 0.5, 10, 0, 56647),
(120874, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120869, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120883, 0.5, 10, 0, 56647),
(120906, 1.534133076667785644, 1.499999880790710449, 0, 56647),
(120871, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120870, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120873, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120589, 0.671816945075988769, 1.70000004768371582, 0, 56647),
(120875, 3.302712678909301757, 2.599999904632568359, 0, 56647),
(120868, 3.302712678909301757, 2.599999904632568359, 0, 56647);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `StaticFlags3`=256, `VerifiedBuild`=56647 WHERE (`Entry`=221628 AND `DifficultyID`=0); -- 221628 (Landing Stalker) - CannotSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=227131 AND `DifficultyID`=0); -- 227131 (Austin Huxworth) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2861, `StaticFlags1`=805306368, `VerifiedBuild`=56647 WHERE (`Entry`=227239 AND `DifficultyID`=0); -- 227239 (Patrolling Swarmite) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=217467 AND `DifficultyID`=0); -- 217467 (Tes'ka) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=221190 AND `DifficultyID`=0); -- 221190 (Loyalist Threadblade) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218209 AND `DifficultyID`=0); -- 218209 (Tyro Uwe) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218207 AND `DifficultyID`=0); -- 218207 (Clutchmother Marn'tiq) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2861, `StaticFlags1`=805306368, `VerifiedBuild`=56647 WHERE (`Entry`=227214 AND `DifficultyID`=0); -- 227214 (Patrolling Swarmite) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2861, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=211816 AND `DifficultyID`=0); -- 211816 (Bazaar Sentry) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218210 AND `DifficultyID`=0); -- 218210 (Tyro Whalekk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2803, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224188 AND `DifficultyID`=0); -- 224188 (Ghos'opp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=536870912, `StaticFlags3`=256, `VerifiedBuild`=56647 WHERE (`Entry`=208509 AND `DifficultyID`=0); -- 208509 (Pully) - Floating - CannotSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=55370 AND `DifficultyID`=1); -- 55370 (General Purpose Bunny ZTO) - Floating - CannotSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218206 AND `DifficultyID`=0); -- 218206 (Caretaker Hulmes) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218221 AND `DifficultyID`=0); -- 218221 (Umbral Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=217466 AND `DifficultyID`=0); -- 217466 (Ves'ka) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218169 AND `DifficultyID`=0); -- 218169 (Llyot) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=233023 AND `DifficultyID`=0); -- 233023 (Unstable Mixture) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223114 AND `DifficultyID`=0); -- 223114 (Weave-Rat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216326 AND `DifficultyID`=0); -- 216326 (Ascended Neophyte) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=221103 AND `DifficultyID`=0); -- 221103 (Hulking Warshell) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=221102 AND `DifficultyID`=0); -- 221102 (Elder Shadeweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=221101 AND `DifficultyID`=0); -- 221101 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=218374 AND `DifficultyID`=0); -- 218374 (Slime Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216329 AND `DifficultyID`=0); -- 216329 (Congealed Droplet) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216342 AND `DifficultyID`=0); -- 216342 (Skittering Assistant) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216320 AND `DifficultyID`=0); -- 216320 (The Coaglamation) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=218067 AND `DifficultyID`=0); -- 218067 (Cocoon) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216339 AND `DifficultyID`=0); -- 216339 (Sureki Unnaturaler) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216328 AND `DifficultyID`=0); -- 216328 (Unstable Test Subject) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=214542 AND `DifficultyID`=0); -- 214542 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220730 AND `DifficultyID`=0); -- 220730 (Royal Venomshell) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224732 AND `DifficultyID`=0); -- 224732 (Covert Webmancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=228361 AND `DifficultyID`=0); -- 228361 (Agile Pursuer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224731 AND `DifficultyID`=0); -- 224731 (Web Marauder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223357 AND `DifficultyID`=0); -- 223357 (Sureki Conscript) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=219675 AND `DifficultyID`=0); -- 219675 (Echoing Shade) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=227612 AND `DifficultyID`=0); -- 227612 (Spider) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=227607 AND `DifficultyID`=0); -- 227607 (Fliq'ri) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230063 AND `DifficultyID`=0); -- 230063 (Ax'ill) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226063 AND `DifficultyID`=0); -- 226063 (Collector Il'zril) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216658 AND `DifficultyID`=0); -- 216658 (Izo, the Grand Splicer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226789 AND `DifficultyID`=0); -- 226789 (Tulumun) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223844 AND `DifficultyID`=0); -- 223844 (Covert Webmancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230065 AND `DifficultyID`=0); -- 230065 (Venomscribe Xesh XI) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230067 AND `DifficultyID`=0); -- 230067 (Royal Journalist Ist'iix) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230066 AND `DifficultyID`=0); -- 230066 (Assistant Tik) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=222013 AND `DifficultyID`=0); -- 222013 ([DNT] Web Barrier Target) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=223716 AND `DifficultyID`=0); -- 223716 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=226177 AND `DifficultyID`=0); -- 226177 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=228428 AND `DifficultyID`=0); -- 228428 ([DNT] Spy Visual) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=229682 AND `DifficultyID`=0); -- 229682 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230053 AND `DifficultyID`=0); -- 230053 (Profiteer Xir'ek) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223181 AND `DifficultyID`=0); -- 223181 (Agile Pursuer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223182 AND `DifficultyID`=0); -- 223182 (Web Marauder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226055 AND `DifficultyID`=0); -- 226055 (Profiteer Z'kaxt) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226056 AND `DifficultyID`=0); -- 226056 (Collector Z'til) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230052 AND `DifficultyID`=0); -- 230052 (Profiteer Ri'za) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220408 AND `DifficultyID`=0); -- 220408 (Kiki) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220409 AND `DifficultyID`=0); -- 220409 (Zeki) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220407 AND `DifficultyID`=0); -- 220407 (Silki) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230051 AND `DifficultyID`=0); -- 230051 (Attendant Ak'lii) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230048 AND `DifficultyID`=0); -- 230048 (Xir'ra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=56647 WHERE (`Entry`=223208 AND `DifficultyID`=0); -- 223208 (Favored Novice) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226064 AND `DifficultyID`=0); -- 226064 (Ozrin the Steelweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=225167 AND `DifficultyID`=0); -- 225167 (ELM General Purpose Bunny - Flying (scale x0.01)) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220404 AND `DifficultyID`=0); -- 220404 (Royal Acolyte) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230050 AND `DifficultyID`=0); -- 230050 (Attendant Xeren) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220037 AND `DifficultyID`=0); -- 220037 (Reposing Knight) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230054 AND `DifficultyID`=0); -- 230054 (Assistant Tix'ii) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230049 AND `DifficultyID`=0); -- 230049 (Assistant Vi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=225141 AND `DifficultyID`=0); -- 225141 ([DNT] Web Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=226057 AND `DifficultyID`=0); -- 226057 (Earthen Puppet) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=226060 AND `DifficultyID`=0); -- 226060 (Kobyss Puppet) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=56647 WHERE (`Entry`=229793 AND `DifficultyID`=0); -- 229793 (Dark Proselityzer) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230047 AND `DifficultyID`=0); -- 230047 (Q'ilax) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226053 AND `DifficultyID`=0); -- 226053 (Assistant Ulo'vix) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=229684 AND `DifficultyID`=0); -- 229684 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=56647 WHERE (`Entry`=223203 AND `DifficultyID`=0); -- 223203 (Skittershaw) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=223202 AND `DifficultyID`=0); -- 223202 (Beetle of Burden) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=229681 AND `DifficultyID`=0); -- 229681 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=230056 AND `DifficultyID`=0); -- 230056 (Assistant Ven'ik) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226058 AND `DifficultyID`=0); -- 226058 (Van'atka) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2551, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=223771 AND `DifficultyID`=0); -- 223771 ([DNT]Cosmetic Flavor) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220004 AND `DifficultyID`=0); -- 220004 (Ascended Aristocrat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222538 AND `DifficultyID`=0); -- 222538 (Loyal Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220423 AND `DifficultyID`=0); -- 220423 (Retired Lord Vul'azak) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `VerifiedBuild`=56647 WHERE (`Entry`=219983 AND `DifficultyID`=0); -- 219983 (Hollows Resident) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220012 AND `DifficultyID`=0); -- 220012 (Hollows Merchant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=229680 AND `DifficultyID`=0); -- 229680 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220793 AND `DifficultyID`=0); -- 220793 (Favored Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=221003 AND `DifficultyID`=0); -- 221003 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=219984 AND `DifficultyID`=0); -- 219984 (Xeph'itik) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220401 AND `DifficultyID`=0); -- 220401 (Pale Priest) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216648 AND `DifficultyID`=0); -- 216648 (Nx) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=220769 AND `DifficultyID`=0); -- 220769 (Orator Krix'vizk) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216649 AND `DifficultyID`=0); -- 216649 (Vx) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=220783 AND `DifficultyID`=0); -- 220783 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=225962 AND `DifficultyID`=0); -- 225962 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220777 AND `DifficultyID`=0); -- 220777 (Executor Nizrek) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224329 AND `DifficultyID`=0); -- 224329 (Visiting Merchant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224330 AND `DifficultyID`=0); -- 224330 (Maraclozh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220479 AND `DifficultyID`=0); -- 220479 (Visiting Merchant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224331 AND `DifficultyID`=0); -- 224331 (Phylleus) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224324 AND `DifficultyID`=0); -- 224324 (Silkswooner Waree) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2551, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=204401 AND `DifficultyID`=0); -- 204401 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=216619 AND `DifficultyID`=0); -- 216619 (Orator Krix'vizk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=223254 AND `DifficultyID`=0); -- 223254 (Queen Ansurek) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220197 AND `DifficultyID`=0); -- 220197 (Royal Swarmguard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=220782 AND `DifficultyID`=0); -- 220782 (Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224327 AND `DifficultyID`=0); -- 224327 (Violesca) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220196 AND `DifficultyID`=0); -- 220196 (Herald of Ansurek) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224320 AND `DifficultyID`=0); -- 224320 (Tes'ka) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224321 AND `DifficultyID`=0); -- 224321 (Ves'ka) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220353 AND `DifficultyID`=0); -- 220353 (Umbral Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220351 AND `DifficultyID`=0); -- 220351 (Umbral Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220199 AND `DifficultyID`=0); -- 220199 (Battle Scarab) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220195 AND `DifficultyID`=0); -- 220195 (Sureki Silkbinder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220193 AND `DifficultyID`=0); -- 220193 (Sureki Venomblade) - CanSwim

-- Path for Battle Scarab
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+34;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+34, @CGUID+34, 0, 0, 515, 1, 6),
(@CGUID+34, @CGUID+20, 3, 300, 515, 1, 6),
(@CGUID+34, @CGUID+3, 3, 60, 515, 1, 6);

SET @MOVERGUID := @CGUID+34;
SET @ENTRY := 220199;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Battle Scarab - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1614.3368, -904.4809, -1249.4818, NULL, 0),
(@PATH, 1, -1618.1216, -914.3941, -1249.4818, NULL, 6176),
(@PATH, 2, -1614.3368, -904.4809, -1249.4818, NULL, 0),
(@PATH, 3, -1613.7673, -892.8802, -1249.4818, NULL, 0),
(@PATH, 4, -1613.566, -882.23785, -1249.4818, NULL, 0),
(@PATH, 5, -1613.8646, -867.7083, -1249.8328, NULL, 0),
(@PATH, 6, -1614.4896, -854.5469, -1250.3489, NULL, 4987),
(@PATH, 7, -1613.8646, -867.7083, -1249.8328, NULL, 0),
(@PATH, 8, -1613.566, -882.23785, -1249.4818, NULL, 0),
(@PATH, 9, -1613.7673, -892.8802, -1249.4818, NULL, 0);

UPDATE `creature` SET `position_x`=-1614.3368, `position_y`=-904.4809, `position_z`=-1249.4818, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Royal Swarmguard
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+32;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+32, @CGUID+32, 0, 0, 515, 0, 0),
(@CGUID+32, @CGUID+91, 4, 30, 515, 0, 0),
(@CGUID+32, @CGUID+92, 8, 30, 515, 0, 0),
(@CGUID+32, @CGUID+87, 10, 330, 515, 0, 0),
(@CGUID+32, @CGUID+89, 14, 330, 515, 0, 0);

SET @MOVERGUID := @CGUID+32;
SET @ENTRY := 220197;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Royal Swarmguard - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1732.8021, -988.8299, -1244.1909, NULL, 0),
(@PATH, 1, -1714.9462, -1007.2239, -1244.1843, NULL, 0),
(@PATH, 2, -1686.3403, -1017.1215, -1244.2902, NULL, 0),
(@PATH, 3, -1660.243, -1018.3577, -1244.1986, NULL, 5215),
(@PATH, 4, -1686.3403, -1017.1215, -1244.2902, NULL, 0),
(@PATH, 5, -1714.9462, -1007.2239, -1244.1843, NULL, 0),
(@PATH, 6, -1732.8021, -988.8299, -1244.1909, NULL, 0),
(@PATH, 7, -1750.842, -972.0972, -1244.2229, NULL, 0),
(@PATH, 8, -1768.7379, -962.434, -1244.1812, NULL, 0),
(@PATH, 9, -1788.0486, -965.09375, -1244.1262, NULL, 0),
(@PATH, 10, -1798.441, -977.9965, -1244.0673, NULL, 5192),
(@PATH, 11, -1788.0486, -965.09375, -1244.1262, NULL, 0),
(@PATH, 12, -1768.7379, -962.434, -1244.1812, NULL, 0),
(@PATH, 13, -1750.842, -972.0972, -1244.2229, NULL, 0);

UPDATE `creature` SET `position_x`=-1732.8021, `position_y`=-988.8299, `position_z`=-1244.1909, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Royal Swarmguard
SET @MOVERGUID := @CGUID+134;
SET @ENTRY := 220197;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Royal Swarmguard - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1913.7673, -1027.5625, -1237.2173, NULL, 0),
(@PATH, 1, -1915.3733, -1009.2813, -1237.2173, NULL, 0),
(@PATH, 2, -1912.507, -998.44446, -1237.2173, NULL, 0),
(@PATH, 3, -1903.8698, -993.88544, -1237.2173, NULL, 0),
(@PATH, 4, -1893.368, -997.441, -1237.2173, NULL, 0),
(@PATH, 5, -1890.7535, -1007.8455, -1237.2173, NULL, 0),
(@PATH, 6, -1891.4375, -1021.0434, -1237.2173, NULL, 0),
(@PATH, 7, -1900.2517, -1033.4601, -1237.2173, NULL, 0);

UPDATE `creature` SET `position_x`=-1913.7673, `position_y`=-1027.5625, `position_z`=-1237.2173, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Heral of Ansurek
SET @MOVERGUID := @CGUID+136;
SET @ENTRY := 220196;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Herald of Ansurek - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1728.7587, -1180.106, -1237.8392, NULL, 0),
(@PATH, 1, -1743.75, -1181.3698, -1237.8392, NULL, 0),
(@PATH, 2, -1754.8142, -1167.3055, -1237.9293, NULL, 0),
(@PATH, 3, -1760.5729, -1155.1666, -1237.9291, NULL, 4887),
(@PATH, 4, -1754.8142, -1167.3055, -1237.9293, NULL, 0),
(@PATH, 5, -1743.75, -1181.3698, -1237.8392, NULL, 0),
(@PATH, 6, -1728.7587, -1180.106, -1237.8392, NULL, 0),
(@PATH, 7, -1719.2379, -1174.0764, -1237.8392, NULL, 4922);

UPDATE `creature` SET `position_x`=-1728.7587, `position_y`=-1180.106, `position_z`=-1237.8392, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');
