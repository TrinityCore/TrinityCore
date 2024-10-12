SET @CGUID := 10003062;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+431;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1882.35595703125, -1208.111083984375, -1259.725341796875, 1.112182378768920898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+1, 223771, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1995.4617919921875, -1235.09033203125, -1239.642822265625, 0.359100103378295898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- [DNT]Cosmetic Flavor (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 449529 - [DNT]Cosmetic Flavor)
(@CGUID+2, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1856.609375, -1174.3958740234375, -1242.965087890625, 3.922076702117919921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 446381 - [DNT] Toxic Fumes Proximity Warning)
(@CGUID+3, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1873.8316650390625, -1193.3038330078125, -1254.58740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+4, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1968.420166015625, -1243.5885009765625, -1239.693603515625, 3.269999504089355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 449509 - Submerge)
(@CGUID+5, 219984, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1981.0504150390625, -1238.7413330078125, -1238.4632568359375, 1.396263360977172851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Xeph'itik (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+6, 213839, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1923.1561279296875, -1181.7625732421875, -1242.5018310546875, 3.910244464874267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 428569 - Passive, 413569 - Bot AI Follow Advert)
(@CGUID+7, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1989.9879150390625, -1244.99658203125, -1239.642822265625, 0.481543183326721191, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 449509 - Submerge)
(@CGUID+8, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1993.5989990234375, -1237.904541015625, -1239.642822265625, 1.977751851081848144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+9, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1888.578125, -1199.2691650390625, -1259.725341796875, 0.373740047216415405, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+10, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1974.4427490234375, -1239.5242919921875, -1239.5550537109375, 3.775453805923461914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+11, 210931, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1987.421875, -1246.5382080078125, -1239.642822265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+12, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1978.0660400390625, -1231.078125, -1239.8804931640625, 4.154095649719238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+13, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1980.329833984375, -1229.2864990234375, -1239.8682861328125, 4.208368778228759765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 449509 - Submerge)
(@CGUID+14, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1982.2430419921875, -1250.451416015625, -1239.642822265625, 1.354627490043640136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 449509 - Submerge)
(@CGUID+15, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1969.1927490234375, -1240.5086669921875, -1239.7978515625, 3.904799222946166992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+16, 220353, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1862.5242919921875, -1204.0555419921875, -1260.206298828125, 3.947084903717041015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+17, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1974.9879150390625, -1237.7708740234375, -1239.584716796875, 4.292359352111816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+18, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2013.3072509765625, -1258.35595703125, -1239.642822265625, 3.684640884399414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+19, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1992.467041015625, -1248.017333984375, -1239.642822265625, 0.427269577980041503, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+20, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2034.017333984375, -1207.7137451171875, -1244.1881103515625, 1.133999109268188476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses) (possible waypoints or random movement)
(@CGUID+21, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2026.0833740234375, -1195.3489990234375, -1244.13134765625, 4.022299766540527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+22, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2024.5521240234375, -1219.717041015625, -1244.094482421875, 5.830849647521972656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+23, 220479, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2015.1319580078125, -1212.796875, -1244.118408203125, 2.640157699584960937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Visiting Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+24, 220351, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2036.2117919921875, -1133.2760009765625, -1253.866455078125, 3.573817729949951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+25, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2023.267333984375, -1221.82470703125, -1244.09716796875, 1.552996754646301269, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity)
(@CGUID+26, 225962, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1843, -1140, -1244.1300048828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 454706 - Advert)
(@CGUID+27, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2013.0382080078125, -1206.3125, -1244.13134765625, 4.022299766540527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+28, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2034.5816650390625, -1201.861083984375, -1244.125, 5.037820816040039062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+29, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1993.4271240234375, -1266.1041259765625, -1239.642822265625, 5.525959968566894531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+30, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2022.1146240234375, -1219.203125, -1244.1007080078125, 3.937562465667724609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+31, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1989.1597900390625, -1249.0660400390625, -1239.642822265625, 1.17305910587310791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+32, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1990.3160400390625, -1267.5694580078125, -1239.642822265625, 3.076747894287109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+33, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1999.1041259765625, -1238.717041015625, -1239.642822265625, 1.019457578659057617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+34, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2030.4444580078125, -1204.3072509765625, -1244.1243896484375, 3.258608818054199218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+35, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1912.2916259765625, -1321.1475830078125, -1244.027587890625, 2.377470970153808593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+36, 220004, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2004.8924560546875, -1285.720703125, -1238.810791015625, 2.378390789031982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+37, 220004, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2051.572265625, -1241.7059326171875, -1244.17626953125, 6.107731342315673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2048.350830078125, -1221.744384765625, -1244.18115234375, 4.544384002685546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 229680, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2010.13720703125, -1276.470458984375, -1239.642822265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+40, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2063.9462890625, -1215.1302490234375, -1243.586181640625, 1.23587346076965332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+41, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2000.533447265625, -1296.62646484375, -1239.0360107421875, 2.190282583236694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 220004, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2035.9844970703125, -1259.759521484375, -1239.0223388671875, 5.545469284057617187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2061.37158203125, -1297.09375, -1238.3660888671875, 5.748348712921142578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+44, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1870.015625, -1354.8367919921875, -1243.7457275390625, 0.66209489107131958, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+45, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2074.751953125, -1261.0977783203125, -1243.8143310546875, 1.395641088485717773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses) (possible waypoints or random movement)
(@CGUID+46, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2055.104248046875, -1150.71875, -1243.166748046875, 0.670256376266479492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 446381 - [DNT] Toxic Fumes Proximity Warning)
(@CGUID+47, 230056, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 1, -2050.52685546875, -1185.3111572265625, -1244.2147216796875, 2.652196168899536132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Assistant Ven'ik (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 222538, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1997.052490234375, -1297.626708984375, -1240.1700439453125, 2.036258935928344726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+49, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2024.3975830078125, -1283.37158203125, -1239.642822265625, 0.518206417560577392, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+50, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1959.1861572265625, -1358.203369140625, -1244.185302734375, 3.194519996643066406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses) (possible waypoints or random movement)
(@CGUID+51, 222538, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2053.797119140625, -1243.7183837890625, -1244.17431640625, 6.134992122650146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2060.046875, -1215.2586669921875, -1244.13134765625, 2.417301177978515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+53, 222538, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1943.954833984375, -1304.78125, -1244.0318603515625, 1.479317784309387207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+54, 210931, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2008.107666015625, -1278.8021240234375, -1239.642822265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+55, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2122.986083984375, -1198.1961669921875, -1244.100830078125, 5.026287555694580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+56, 222538, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2049.5458984375, -1243.946044921875, -1244.18017578125, 6.024434566497802734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+57, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1973.9605712890625, -1434.8876953125, -1244.185302734375, 1.932718515396118164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses) (possible waypoints or random movement)
(@CGUID+58, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2067.3212890625, -1367.2916259765625, -1237.560791015625, 1.715436339378356933, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+59, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2029.9334716796875, -1422.94921875, -1239.7261962890625, 0.819904327392578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses, 441664 - Webbed Candle)
(@CGUID+60, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1958.2847900390625, -1418.9097900390625, -1244.1019287109375, 3.080533742904663085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+61, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2170.078125, -1213.7847900390625, -1244.0985107421875, 3.727760791778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+62, 220423, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2046.468505859375, -1460.04052734375, -1239.7261962890625, 0.818691849708557128, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Retired Lord Vul'azak (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+63, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2043.4422607421875, -1441.9638671875, -1239.7261962890625, 0.573750495910644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses, 441664 - Webbed Candle)
(@CGUID+64, 220401, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2213.453857421875, -1251.7979736328125, -1239.7261962890625, 5.67975616455078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+65, 220004, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2063.458251953125, -1260.0660400390625, -1244.101806640625, 6.241899967193603515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+66, 229681, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1955.3055419921875, -1388.6632080078125, -1244.1019287109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+67, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2016.3316650390625, -1261.203125, -1239.642822265625, 1.051453828811645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+68, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2074.135498046875, -1224.8507080078125, -1244.131103515625, 1.816873431205749511, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+69, 229793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2079.795166015625, -1209.670166015625, -1244.1141357421875, 1.041772007942199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Dark Proselityzer (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+70, 222538, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1993.23095703125, -1323.7117919921875, -1244.1007080078125, 5.445972442626953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+71, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1908.1632080078125, -1335.545166015625, -1244.1019287109375, 6.223551750183105468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+72, 220004, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1999.4322509765625, -1318.41845703125, -1244.1019287109375, 3.222875833511352539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+73, 226058, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1950.38720703125, -1292.13720703125, -1244.0318603515625, 4.82741546630859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Van'atka (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+74, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2037.03125, -1206.6771240234375, -1244.108642578125, 0.374407410621643066, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+75, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2032.482666015625, -1208.0816650390625, -1244.114501953125, 1.646299004554748535, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+76, 230047, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 1, -2040.828125, -1182.1492919921875, -1244.054931640625, 4.137341499328613281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Q'ilax (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+77, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2073.26904296875, -1212.607666015625, -1244.13134765625, 6.241950035095214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+78, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2072.767333984375, -1220.7916259765625, -1244.1312255859375, 3.42918252944946289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+79, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2016.69970703125, -1258.5086669921875, -1239.642822265625, 5.715798854827880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+80, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1943.970458984375, -1301.076416015625, -1244.0318603515625, 5.158585071563720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+81, 229684, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2137.6650390625, -1224.998291015625, -1244.1160888671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+82, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2019.927978515625, -1269.580810546875, -1239.7261962890625, 2.763889074325561523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+83, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2089.045166015625, -1200.0347900390625, -1244.13134765625, 5.038055419921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+84, 226060, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1990.017333984375, -1391.52783203125, -1244.1019287109375, 0.983904838562011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Kobyss Puppet (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 452338 - [DNT] Kobyss Pause Animation, 452885 - [DNT] Puppet)
(@CGUID+85, 219983, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1940.7708740234375, -1302.90283203125, -1244.0318603515625, 2.774018764495849609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+86, 226057, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -1989.361083984375, -1393.795166015625, -1242.4384765625, 0.097576089203357696, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Earthen Puppet (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 452345 - [DNT] Earthen Pause Animation, 452885 - [DNT] Puppet)
(@CGUID+87, 220012, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2084.90625, -1202.48095703125, -1244.13134765625, 4.217212200164794921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+88, 226053, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 1, -1933.52783203125, -1301.576416015625, -1242.27392578125, 3.273421287536621093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Assistant Ulo'vix (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+89, 220793, 2669, 14979, 15111, '1,2,8,23', 0, 0, 0, 0, -2049.135498046875, -1296.045166015625, -1239.642822265625, 3.409516572952270507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: Umbral Bazaar - Difficulty: Follower) CreateObject1
(@CGUID+90, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1991.439208984375, -1354.7847900390625, -1244.1019287109375, 4.130174160003662109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+91, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2094.548583984375, -1212.4722900390625, -1243.953125, 0.257000356912612915, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+92, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1923.6302490234375, -1349.1353759765625, -1244.1019287109375, 1.479317784309387207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+93, 220401, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2075.14013671875, -1488.5230712890625, -1239.7261962890625, 0.75350189208984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses) (possible waypoints or random movement)
(@CGUID+94, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2020.328125, -1281.357666015625, -1239.642822265625, 3.408386945724487304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441952 - Unseen Disguise)
(@CGUID+95, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1938.2742919921875, -1354.1649169921875, -1244.109375, 3.872469425201416015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+96, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1945.1822509765625, -1310.0816650390625, -1242.506591796875, 5.260516166687011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book)
(@CGUID+97, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2057.8681640625, -1301.75, -1239.642822265625, 2.343926906585693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+98, 220401, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2065.677001953125, -1492.5103759765625, -1239.642822265625, 2.604127883911132812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+99, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1956.5252685546875, -1358.3458251953125, -1244.185302734375, 0.463537663221359252, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+100, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1925.060791015625, -1316.0191650390625, -1243.51953125, 5.260516166687011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book)
(@CGUID+101, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2061.09716796875, -1210.7396240234375, -1244.13134765625, 4.136780738830566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+102, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2065.748291015625, -1209.71875, -1244.13134765625, 5.495784759521484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+103, 230049, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2018.88720703125, -1352.0191650390625, -1244.0504150390625, 5.57469940185546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Assistant Vi (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+104, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1941.7725830078125, -1363.951416015625, -1244.1019287109375, 1.143620967864990234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+105, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1922.2725830078125, -1317.3333740234375, -1243.797607421875, 3.313221693038940429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+106, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1990.467041015625, -1325.875, -1244.1007080078125, 3.163851261138916015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+107, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2002.6302490234375, -1320.0225830078125, -1244.1019287109375, 0.612755000591278076, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+108, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2044.0989990234375, -1287.6597900390625, -1239.642822265625, 4.57736063003540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+109, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1993.765625, -1327.2916259765625, -1244.1007080078125, 0.553729236125946044, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+110, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2067.10595703125, -1217.1961669921875, -1244.13134765625, 2.431928873062133789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+111, 230054, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1944.390625, -1368.248291015625, -1244.1019287109375, 5.945900917053222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Assistant Tix'ii (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+112, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2044.279541015625, -1290.2569580078125, -1239.642822265625, 2.311189174652099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+113, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2060.68408203125, -1257.13720703125, -1244.1019287109375, 4.651025295257568359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+114, 230050, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1994.26220703125, -1404.84033203125, -1244.1019287109375, 2.902500391006469726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Attendant Xeren (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+115, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2059.361083984375, -1260.7603759765625, -1244.1019287109375, 3.506198883056640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+116, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1995.607666015625, -1362.52783203125, -1244.1019287109375, 0.665976166725158691, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 462571 - [DNT] High Hollows NPC Convo Proximity)
(@CGUID+117, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1934.982666015625, -1326.779541015625, -1244.149658203125, 4.386659622192382812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+118, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1904.0694580078125, -1357.0347900390625, -1244.1019287109375, 3.923240900039672851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+119, 226064, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2072.98095703125, -1269.4791259765625, -1244.1019287109375, 2.120448827743530273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ozrin the Steelweaver (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 453055 - Working)
(@CGUID+120, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2078.85595703125, -1224.2413330078125, -1244.13134765625, 0.544981837272644042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+121, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2077.2587890625, -1219.0816650390625, -1244.13134765625, 5.208596229553222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+122, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1992.734375, -1376.6788330078125, -1244.1019287109375, 2.389685392379760742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+123, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2051.645751953125, -1300.795166015625, -1239.642822265625, 2.578426122665405273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+124, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1935.7742919921875, -1329.123291015625, -1244.150390625, 1.245066642761230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+125, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2056.78466796875, -1298.7882080078125, -1239.642822265625, 2.693741559982299804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+126, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2103.12158203125, -1306.279541015625, -1239.642822265625, 0.926061749458312988, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+127, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1889.4583740234375, -1351.34033203125, -1244.1019287109375, 5.323124408721923828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+128, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1915.625, -1320.73095703125, -1244.1019287109375, 0.572720229625701904, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+129, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2107.31982421875, -1176.5625, -1244.2147216796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2028.47314453125, -1368.4207763671875, -1239.72607421875, 2.022004365921020507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441664 - Webbed Candle) (possible waypoints or random movement)
(@CGUID+131, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2034.57958984375, -1367.6531982421875, -1239.7261962890625, 2.309040069580078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441664 - Webbed Candle) (possible waypoints or random movement)
(@CGUID+132, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2029.19287109375, -1373.573486328125, -1239.7261962890625, 2.309042930603027343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441664 - Webbed Candle) (possible waypoints or random movement)
(@CGUID+133, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2025.619384765625, -1374.8447265625, -1239.7261962890625, 2.056435108184814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441664 - Webbed Candle) (possible waypoints or random movement)
(@CGUID+134, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2087.039794921875, -1331.9447021484375, -1239.7261962890625, 0.688213229179382324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+135, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2103.972900390625, -1172.0465087890625, -1243.615234375, 4.959554672241210937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+136, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2087.814208984375, -1326.108154296875, -1239.7261962890625, 0.688206255435943603, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+137, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2079.65625, -1261.1163330078125, -1244.1019287109375, 5.204418182373046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+138, 225167, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2077.24755859375, -1205.014404296875, -1242.5748291015625, 2.701981544494628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- ELM General Purpose Bunny - Flying (scale x0.01) (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+139, 230048, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2029.6910400390625, -1341.0364990234375, -1243.996337890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Xir'ra (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+140, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2019.90380859375, -1386.817138671875, -1239.7261962890625, 1.80440223217010498, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+141, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2024.4281005859375, -1385.9320068359375, -1239.7261962890625, 1.915707945823669433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2130.932373046875, -1227.84033203125, -1244.1019287109375, 1.646299004554748535, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+143, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2020.52001953125, -1390.8944091796875, -1239.7261962890625, 1.915717959403991699, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+144, 230051, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1989.967041015625, -1433.9010009765625, -1244.1019287109375, 3.834650039672851562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Attendant Ak'lii (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+145, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2024.284423828125, -1392.2469482421875, -1239.7261962890625, 1.915717959403991699, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+146, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2027.51904296875, -1389.15869140625, -1239.7261962890625, 1.512018442153930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+147, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2086.944580078125, -1206.2552490234375, -1244.13134765625, 2.84209442138671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+148, 220407, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2041.57958984375, -1350.415283203125, -1239.7261962890625, 1.813855528831481933, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Silki (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+149, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2133.03125, -1221.6197509765625, -1244.1292724609375, 5.056973457336425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+150, 220408, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2047.576416015625, -1345.197265625, -1239.7261962890625, 2.142071247100830078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Kiki (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+151, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2125.210205078125, -1309.6285400390625, -1239.642822265625, 0.878944337368011474, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+152, 230052, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1988.3507080078125, -1369.5364990234375, -1244.1019287109375, 0.557126879692077636, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Profiteer Ri'za (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+153, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2107.302001953125, -1263.8072509765625, -1242.103271484375, 2.241435050964355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+154, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2062.776123046875, -1364.3333740234375, -1238.4783935546875, 3.313221693038940429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+155, 229793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2139.604248046875, -1333.2603759765625, -1239.443603515625, 2.21988534927368164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Dark Proselityzer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+156, 220409, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2060.890380859375, -1343.141845703125, -1239.7261962890625, 2.116253852844238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Zeki (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+157, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2111.670166015625, -1265.248291015625, -1219.0054931640625, 4.394376754760742187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+158, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2109.0869140625, -1261.5572509765625, -1242.103271484375, 5.383028030395507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+159, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2098.21533203125, -1303.9166259765625, -1239.642822265625, 2.728485107421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+160, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2099.623291015625, -1306.579833984375, -1239.642822265625, 1.760223746299743652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+161, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2050.62158203125, -1409.798583984375, -1237.560791015625, 0.335566818714141845, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+162, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2108.70654296875, -1266.65625, -1219.0289306640625, 3.772094964981079101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+163, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2142.583251953125, -1227.7833251953125, -1244.1890869140625, 0.978387534618377685, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+164, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2102.109375, -1301.9375, -1239.642822265625, 5.749114513397216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+165, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2098.875, -1300.6319580078125, -1239.642822265625, 4.168450355529785156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+166, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2069.732666015625, -1359.657958984375, -1239.642822265625, 4.924743175506591796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+167, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2112.47216796875, -1272.3194580078125, -1219.1929931640625, 1.48403632640838623, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+168, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2109.763916015625, -1263.9600830078125, -1242.103271484375, 0.633333802223205566, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+169, 220401, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2224.65283203125, -1474.0660400390625, -1239.642822265625, 1.727697014808654785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+170, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2091.4931640625, -1204.8507080078125, -1244.13134765625, 0.374407410621643066, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+171, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1999.2117919921875, -1365.5728759765625, -1244.1019287109375, 5.003085613250732421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+172, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2123.210205078125, -1268.1927490234375, -1219.056396484375, 4.245382308959960937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+173, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2044.4757080078125, -1429.1978759765625, -1239.642822265625, 2.533809185028076171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+174, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2125.189208984375, -1304.6978759765625, -1239.642822265625, 5.291898727416992187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+175, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2159.842529296875, -1272.2449951171875, -1239.7261962890625, 5.634772300720214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+176, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2144.68408203125, -1334.7691650390625, -1239.642822265625, 3.821761131286621093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+177, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2124.3125, -1275.3958740234375, -1242.103271484375, 0.595019817352294921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+178, 229793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2053.2587890625, -1423.373291015625, -1237.567626953125, 5.414540767669677734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Dark Proselityzer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 323849 - Shadow Channeling)
(@CGUID+179, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2044.2899169921875, -1426.44970703125, -1239.642822265625, 2.761893033981323242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+180, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2122.270751953125, -1274.013916015625, -1242.103271484375, 4.245382308959960937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+181, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2072.225830078125, -1361.6197509765625, -1239.642822265625, 5.425255298614501953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+182, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2120.7900390625, -1307.3819580078125, -1239.642822265625, 3.161764383316040039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+183, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2073.588623046875, -1358.2222900390625, -1239.642822265625, 5.263126850128173828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+184, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2167.866455078125, -1260.595458984375, -1239.642333984375, 0.043014883995056152, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+185, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2038.234375, -1402.07470703125, -1237.5648193359375, 0.419764250516891479, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book)
(@CGUID+186, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2047.5399169921875, -1431.015625, -1239.642822265625, 2.192654609680175781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+187, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2037.375, -1404.44970703125, -1237.566650390625, 0.194437384605407714, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+188, 220401, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2213.295166015625, -1529.3992919921875, -1239.408447265625, 4.226968288421630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Pale Priest (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 441951 - Keen Senses)
(@CGUID+189, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2125.251708984375, -1269.57470703125, -1219.056396484375, 0.59507530927658081, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+190, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2049.6650390625, -1430.1510009765625, -1239.5374755859375, 2.07044529914855957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+191, 223203, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2080.74267578125, -1491.3734130859375, -1239.7261962890625, 1.363086462020874023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skittershaw (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+192, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2045.6771240234375, -1410.1632080078125, -1237.560791015625, 2.618386507034301757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+193, 226055, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1991.796875, -1396.970458984375, -1244.1019287109375, 0.398477077484130859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Profiteer Z'kaxt (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+194, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2048.052001953125, -1405.595458984375, -1237.560791015625, 4.748521804809570312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+195, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2075.251708984375, -1404.623291015625, -1237.560791015625, 5.050091743469238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM))
(@CGUID+196, 220479, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2134.182373046875, -1342.0816650390625, -1239.642822265625, 1.701976656913757324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Visiting Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+197, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2004.5086669921875, -1447.9913330078125, -1239.642822265625, 4.606107711791992187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+198, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2130.897705078125, -1340.9322509765625, -1239.642822265625, 2.881426334381103515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+199, 225167, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2143.073486328125, -1328.6978759765625, -1236.005126953125, 2.308747768402099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- ELM General Purpose Bunny - Flying (scale x0.01) (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+200, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2002.8350830078125, -1452.6649169921875, -1239.642822265625, 2.323286771774291992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+201, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2181.92529296875, -1312.8021240234375, -1239.642822265625, 6.229837894439697265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+202, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2073.114501953125, -1422.829833984375, -1237.5654296875, 3.726693391799926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM))
(@CGUID+203, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2122.494873046875, -1425.1666259765625, -1239.642822265625, 0.335566818714141845, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+204, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2075.81591796875, -1424.55908203125, -1237.5672607421875, 0.478906124830245971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM))
(@CGUID+205, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2148.69970703125, -1340.75, -1238.777587890625, 1.307129502296447753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+206, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2159.272705078125, -1394.3072509765625, -1237.3936767578125, 1.985664129257202148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+207, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2171.744873046875, -1398.1597900390625, -1237.3936767578125, 6.11780405044555664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+208, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2072.489501953125, -1407.1285400390625, -1237.560791015625, 2.254210948944091796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM))
(@CGUID+209, 230053, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1990.873291015625, -1425.5816650390625, -1244.1019287109375, 6.134226322174072265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Profiteer Xir'ek (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+210, 229682, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2109.23779296875, -1520.19970703125, -1239.642822265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Path Helper (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+211, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2033.6146240234375, -1473.578125, -1239.642822265625, 3.871032238006591796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+212, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2072.1328125, -1483.0885009765625, -1239.7261962890625, 4.766520500183105468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+213, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2035.5069580078125, -1478.1666259765625, -1239.642822265625, 1.588211297988891601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+214, 223716, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2122.56591796875, -1398.1197509765625, -1207.1551513671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+215, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2133.767333984375, -1450.3853759765625, -1239.642822265625, 4.6455841064453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+216, 226177, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2122.569580078125, -1398.1197509765625, -1207.1566162109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+217, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2184.568115234375, -1291.752685546875, -1238.8642578125, 5.7859039306640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+218, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1946.3385009765625, -1439.549072265625, -1244.185302734375, 2.715021371841430664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+219, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1943.282470703125, -1437.642822265625, -1244.185302734375, 2.715010881423950195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+220, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -1942.4791259765625, -1356.7569580078125, -1244.111083984375, 6.149664878845214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+221, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2138.029541015625, -1467.19970703125, -1239.642822265625, 1.056231021881103515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+222, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1941.17724609375, -1440.246826171875, -1244.185302734375, 2.715044021606445312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+223, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1945.1656494140625, -1443.471435546875, -1242.7789306640625, 2.943283319473266601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+224, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2007.7135009765625, -1452.01220703125, -1239.642822265625, 0.453055351972579956, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+225, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2115.0244140625, -1424.0347900390625, -1239.642822265625, 3.294270038604736328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+226, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2068.463623046875, -1487.6492919921875, -1239.642822265625, 5.112520217895507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+227, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1942.040283203125, -1441.4788818359375, -1244.185302734375, 2.678038835525512695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+228, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2119.92529296875, -1420.9617919921875, -1239.642822265625, 4.748521804809570312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+229, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1999.3646240234375, -1500.484375, -1239.642822265625, 0.191932946443557739, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+230, 230066, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2147.625, -1458.98095703125, -1239.642822265625, 5.543409347534179687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Assistant Tik (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+231, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1908.030029296875, -1412.199951171875, -1247.615234375, 3.8460693359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+232, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1904.914794921875, -1405.964111328125, -1247.615234375, 5.761254787445068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+233, 226056, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1934.8160400390625, -1363.4947509765625, -1244.1019287109375, 2.206448554992675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Collector Z'til (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+234, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1992.4132080078125, -1503.345458984375, -1239.642822265625, 2.745917320251464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+235, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1991.9375, -1498.5677490234375, -1239.642822265625, 3.606858491897583007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+236, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1953.4114990234375, -1445.2222900390625, -1244.1019287109375, 1.086314082145690917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+237, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2038.689208984375, -1474.407958984375, -1239.5867919921875, 6.001164913177490234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+238, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1963.8975830078125, -1454.5660400390625, -1244.1019287109375, 5.023231983184814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+239, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1964.57470703125, -1456.96875, -1244.1019287109375, 0.633333802223205566, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+240, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1923.73095703125, -1378.7552490234375, -1247.7196044921875, 0.858093917369842529, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441952 - Unseen Disguise)
(@CGUID+241, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1962.1129150390625, -1456.8160400390625, -1244.1019287109375, 3.203545570373535156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+242, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1952.6197509765625, -1442.8785400390625, -1244.1019287109375, 4.386612892150878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+243, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1923.6458740234375, -1345.4288330078125, -1244.1019287109375, 5.158585071563720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+244, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1920.4461669921875, -1347.2569580078125, -1244.1019287109375, 2.774018764495849609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+245, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1874.6910400390625, -1413.16845703125, -1244.1019287109375, 2.861566543579101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+246, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -1907.1944580078125, -1361.0399169921875, -1244.1019287109375, 0.907514750957489013, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+247, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1872.6754150390625, -1352.71875, -1244.01025390625, 1.919162869453430175, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+248, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1885.767333984375, -1438.6197509765625, -1244.1019287109375, 6.223552227020263671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+249, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2162.744873046875, -1389.982666015625, -1237.3935546875, 4.91081094741821289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+250, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2030.092041015625, -1537.88720703125, -1239.642822265625, 4.567170143127441406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+251, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2039.7569580078125, -1536.3629150390625, -1239.642822265625, 6.156305789947509765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+252, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2104.673583984375, -1507.3958740234375, -1239.642822265625, 6.056636333465576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+253, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2032.13720703125, -1512.2239990234375, -1239.642822265625, 5.260516166687011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+254, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1996.451416015625, -1504.782958984375, -1239.642822265625, 1.601090312004089355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+255, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2035.685791015625, -1539.18408203125, -1239.642822265625, 5.557431221008300781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+256, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1995.28125, -1497.0086669921875, -1239.642822265625, 4.732563972473144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+257, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2031.1180419921875, -1542.5103759765625, -1239.541259765625, 2.262375116348266601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+258, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2041.1649169921875, -1527.1197509765625, -1239.642822265625, 3.203594923019409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+259, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2031.1353759765625, -1519.515625, -1239.642822265625, 0.700606822967529296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+260, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2027.435791015625, -1515.52783203125, -1239.642822265625, 2.745789289474487304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+261, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2013.48095703125, -1526.8021240234375, -1239.642822265625, 2.882274150848388671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+262, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2017.51220703125, -1525.732666015625, -1239.642822265625, 6.023867130279541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+263, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2143.27783203125, -1507.15283203125, -1239.642822265625, 1.479317784309387207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+264, 220404, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2135.09375, -1514.1744384765625, -1239.7261962890625, 0.513072013854980468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Acolyte (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+265, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2043.626708984375, -1527.2725830078125, -1239.642822265625, 0.062002047896385192, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+266, 230065, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2031.65625, -1545.6510009765625, -1239.541259765625, 4.66777801513671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Venomscribe Xesh XI (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+267, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2127.232666015625, -1531.6632080078125, -1239.642822265625, 2.685650587081909179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+268, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1908.6441650390625, -1398.5521240234375, -1247.7196044921875, 4.961475372314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+269, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1908.0364990234375, -1400.9410400390625, -1247.7196044921875, 1.656341314315795898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+270, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1897.74658203125, -1426.6910400390625, -1244.1019287109375, 5.376784324645996093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+271, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1894.9305419921875, -1427.548583984375, -1244.1019287109375, 3.235100984573364257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+272, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1882.6146240234375, -1438.6197509765625, -1244.1019287109375, 3.201447725296020507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+273, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1882.248291015625, -1424.142333984375, -1244.1019287109375, 4.57736063003540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+274, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1882.4288330078125, -1426.7396240234375, -1244.1019287109375, 2.311189174652099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+275, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1857.6441650390625, -1384.9254150390625, -1242.699462890625, 5.830849647521972656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+276, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1879.3021240234375, -1415.9114990234375, -1244.1019287109375, 2.030476093292236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+277, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1900.3021240234375, -1359.09033203125, -1244.1019287109375, 3.308017253875732421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+278, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1902.5035400390625, -1362.1632080078125, -1244.1019287109375, 2.760731935501098632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+279, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1886.9375, -1354.90283203125, -1244.1019287109375, 2.184808969497680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+280, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -1878.138916015625, -1377.2447509765625, -1244.1019287109375, 2.654413223266601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+281, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1873.0728759765625, -1392.7552490234375, -1244.1019287109375, 4.354134559631347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+282, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1905.0242919921875, -1333.892333984375, -1244.1019287109375, 4.57736063003540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+283, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1836.842041015625, -1383.73095703125, -1243.9061279296875, 1.728031516075134277, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+284, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -1881.29345703125, -1375.078125, -1244.1019287109375, 6.149664878845214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+285, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1904.4427490234375, -1337.6302490234375, -1244.1019287109375, 2.745902299880981445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+286, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1871.642333984375, -1395.626708984375, -1244.1019287109375, 2.669141530990600585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+287, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1870.2569580078125, -1393.6129150390625, -1244.1019287109375, 3.40452432632446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+288, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1876.2447509765625, -1350.2430419921875, -1244.01025390625, 0.804765701293945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+289, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1855.2066650390625, -1384.407958984375, -1242.699462890625, 3.937562465667724609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+290, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1856.359375, -1387.032958984375, -1242.699462890625, 1.552996754646301269, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity)
(@CGUID+291, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1841.2760009765625, -1380.7100830078125, -1243.934814453125, 0.896942019462585449, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+292, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1846.5364990234375, -1413.3663330078125, -1243.989013671875, 4.599449634552001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+293, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1848.138916015625, -1415.2725830078125, -1244.0130615234375, 5.920703411102294921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+294, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1835.3836669921875, -1406.467041015625, -1244.0172119140625, 4.907355785369873046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+295, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1845.8316650390625, -1416.1475830078125, -1243.9268798828125, 2.214883327484130859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+296, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -1836.5191650390625, -1408.8072509765625, -1243.99462890625, 0.458134025335311889, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+297, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2099.60107421875, -1493.7244873046875, -1239.7261962890625, 0.506107330322265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds) (possible waypoints or random movement)
(@CGUID+298, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2125.342041015625, -1543.98095703125, -1239.642822265625, 3.774513006210327148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+299, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2119.076416015625, -1556.0972900390625, -1239.642822265625, 0.512775659561157226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+300, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2102.420166015625, -1506.34375, -1239.642822265625, 4.163350105285644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+301, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2128.541748046875, -1556.578125, -1239.6007080078125, 5.412702083587646484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+302, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2102.954833984375, -1509.1632080078125, -1239.642822265625, 1.778783917427062988, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+303, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2112.625, -1527.2135009765625, -1239.642822265625, 3.937562465667724609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+304, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2115.0625, -1527.7274169921875, -1239.642822265625, 5.830849647521972656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+305, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2113.77783203125, -1529.8350830078125, -1239.642822265625, 1.552996754646301269, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity)
(@CGUID+306, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2151.927001953125, -1541.5416259765625, -1239.642822265625, 6.056636333465576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+307, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2143.29345703125, -1503.4461669921875, -1239.642822265625, 5.158585071563720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+308, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2181.329833984375, -1480.939208984375, -1239.642822265625, 4.128038883209228515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+309, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2125.060791015625, -1560.4288330078125, -1239.642822265625, 2.461036205291748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+310, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2140.09375, -1505.2742919921875, -1239.642822265625, 2.774018764495849609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+311, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2130.142333984375, -1533.642333984375, -1239.642822265625, 1.28417205810546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+312, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2127.236083984375, -1547.03125, -1239.642822265625, 1.16439211368560791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+313, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2130.944580078125, -1462.7847900390625, -1239.642822265625, 3.577891111373901367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+314, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2130.489501953125, -1530.0660400390625, -1239.642822265625, 4.95723581314086914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+315, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2135.10595703125, -1491.26220703125, -1222.8800048828125, 0.062536880373954772, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book)
(@CGUID+316, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2148.4150390625, -1541.734375, -1239.642822265625, 3.774513006210327148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+317, 230067, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2133.96875, -1453.3958740234375, -1239.642822265625, 1.003948926925659179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Royal Journalist Ist'iix (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+318, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2189.864501953125, -1485.2864990234375, -1239.642822265625, 0.027808727696537971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+319, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2150.30908203125, -1544.7847900390625, -1239.642822265625, 1.16439211368560791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+320, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2197.505126953125, -1572.375, -1245.239501953125, 3.684640884399414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+321, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2178.78125, -1487.8367919921875, -1239.642822265625, 2.461036205291748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+322, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2209.142333984375, -1589.3680419921875, -1246.4573974609375, 4.286792278289794921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+323, 220012, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2232.765625, -1533.71533203125, -1239.642822265625, 6.089900493621826171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Merchant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+324, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2176.189208984375, -1472.1805419921875, -1239.642822265625, 2.461036205291748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+325, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2182.260498046875, -1575.545166015625, -1245.239501953125, 5.525959968566894531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+326, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2245.529541015625, -1520.189208984375, -1239.642822265625, 2.152094125747680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 462571 - [DNT] High Hollows NPC Convo Proximity)
(@CGUID+327, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2237.739990234375, -1531.02001953125, -1239.6153564453125, 4.41832590103149414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+328, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2179.1494140625, -1577.0103759765625, -1245.239501953125, 3.076747894287109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+329, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2244.93408203125, -1516.2742919921875, -1239.642822265625, 3.734982967376708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+330, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2196.59375, -1489.8697509765625, -1239.642822265625, 2.442901134490966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+331, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2198.482666015625, -1488.282958984375, -1239.642822265625, 6.091755867004394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+332, 227612, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2210.358154296875, -1487.41552734375, -1239.7261962890625, 0.588351249694824218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Spider (Area: High Hollows - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+333, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2200.529541015625, -1575.2222900390625, -1245.239501953125, 1.051453828811645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+334, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2200.897705078125, -1572.52783203125, -1245.2708740234375, 5.715798854827880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+335, 227613, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2216.95263671875, -1485.3150634765625, -1239.7261962890625, 4.200863838195800781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skitterling (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+336, 227613, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2227.8359375, -1482.714599609375, -1239.7261962890625, 3.863513946533203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Skitterling (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+337, 227607, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2218.19970703125, -1475.3472900390625, -1239.642822265625, 4.27731943130493164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Fliq'ri (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+338, 227612, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2220.41796875, -1479.1328125, -1239.7261962890625, 2.413043737411499023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Spider (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+339, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2214.694580078125, -1576.357666015625, -1245.239501953125, 3.733243227005004882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441952 - Unseen Disguise)
(@CGUID+340, 227612, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2223.958984375, -1475, -1239.7261962890625, 3.382659435272216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Spider (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+341, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2237.085205078125, -1563.4166259765625, -1246.366455078125, 3.575915813446044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book)
(@CGUID+342, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2243.642333984375, -1539.282958984375, -1239.408447265625, 3.575915813446044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book)
(@CGUID+343, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2236.0625, -1565.2117919921875, -1246.366455078125, 3.313221693038940429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+344, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2163.123291015625, -1412.2413330078125, -1237.3936767578125, 4.316480636596679687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+345, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2299.069580078125, -1471.21875, -1255.793212890625, 6.119752407073974609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+346, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2297.02783203125, -1469.8367919921875, -1255.805908203125, 3.736612558364868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+347, 216658, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2614.110107421875, -1174.9599609375, -1128.8499755859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Izo, the Grand Splicer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 423679 - Bot AI Follow Advert)
(@CGUID+348, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2154.145751953125, -1400.9947509765625, -1237.3936767578125, 5.835834503173828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+349, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2151.916748046875, -1402.064208984375, -1237.3936767578125, 3.20355534553527832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+350, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2161.697998046875, -1393.8333740234375, -1237.3936767578125, 0.621048390865325927, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+351, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2156.42529296875, -1390.060791015625, -1237.3936767578125, 3.762641191482543945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+352, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2168.43408203125, -1387.2708740234375, -1237.3936767578125, 1.819882631301879882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+353, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2169.041748046875, -1384.8819580078125, -1237.3936767578125, 4.961475372314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+354, 222013, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2168.088623046875, -1345.923583984375, -1195.065185546875, 1.00572359561920166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- [DNT] Web Barrier Target (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+355, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2175.303955078125, -1313.5521240234375, -1239.642822265625, 2.965040922164916992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+356, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2179.404541015625, -1309.3489990234375, -1239.642822265625, 4.962597370147705078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+357, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2177.373291015625, -1316.2100830078125, -1239.642822265625, 1.900090813636779785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+358, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2175.991455078125, -1315.8819580078125, -1239.642822265625, 2.183676958084106445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+359, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2156.49658203125, -1281.3853759765625, -1239.642822265625, 2.954202175140380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+360, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2188.111083984375, -1314.1319580078125, -1239.642822265625, 2.232981204986572265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+361, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2223.3994140625, -1293.388916015625, -1239.642822265625, 4.286792278289794921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+362, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2189.62158203125, -1312.1944580078125, -1239.642822265625, 5.59804534912109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+363, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2158.913330078125, -1280.9271240234375, -1239.642822265625, 0.036960948258638381, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+364, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2136.73779296875, -1263.217041015625, -1242.103271484375, 3.428541421890258789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+365, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2191.678955078125, -1296.204833984375, -1239.642822265625, 1.394799709320068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity)
(@CGUID+366, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2190.126708984375, -1293.796875, -1239.642822265625, 3.779364824295043945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+367, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2192.61279296875, -1293.920166015625, -1239.642822265625, 5.672651290893554687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+368, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2129.979248046875, -1262.0521240234375, -1219.115966796875, 1.262354373931884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+369, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2139.19970703125, -1263.3697509765625, -1242.103271484375, 0.061949584633111953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+370, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2132.817626953125, -1260.46533203125, -1219.170166015625, 0.562952816486358642, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+371, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2165.880126953125, -1263.4913330078125, -1239.642333984375, 0.877124905586242675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+372, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2126.09033203125, -1255.9444580078125, -1219.070556640625, 4.062701225280761718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 434103 - Conversation Aura - Sitting: Talk/Point/Question/Yes/No/Cry/Cheer [DNT])
(@CGUID+373, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2160.807373046875, -1260.2916259765625, -1239.642333984375, 2.641888618469238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+374, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2162.928955078125, -1262.8853759765625, -1239.642333984375, 1.84538733959197998, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+375, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2214.95654296875, -1242.782958984375, -1239.642822265625, 3.684640884399414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+376, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2163.869873046875, -1258.6197509765625, -1239.642333984375, 4.866015434265136718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+377, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2128.89404296875, -1224.0660400390625, -1244.1048583984375, 3.258608818054199218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+378, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2135.48095703125, -1226.435791015625, -1244.130126953125, 0.374407410621643066, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+379, 226789, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2156.17529296875, -1184.954833984375, -1243.8643798828125, 0.573276400566101074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Tulumun (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+380, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2120.37841796875, -1202.3663330078125, -1244.114501953125, 2.160674810409545898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+381, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2122.87158203125, -1204.328125, -1244.106201171875, 1.594446301460266113, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+382, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2124.232666015625, -1200.9322509765625, -1244.095458984375, 1.115772366523742675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+383, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2122.060791015625, -1169.5416259765625, -1244.125244140625, 3.520632266998291015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+384, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2102.24658203125, -1144.4427490234375, -1243.44287109375, 4.427042007446289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+385, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2071.107666015625, -1161.4600830078125, -1244.13134765625, 2.560919761657714843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+386, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2076.296875, -1160.7379150390625, -1244.13134765625, 1.134054422378540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+387, 220793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2184.4150390625, -1174.9305419921875, -1241.3525390625, 5.025944709777832031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+388, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2151.560791015625, -1181.9757080078125, -1244.07666015625, 3.61682891845703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+389, 226063, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2105.3125, -1146.28125, -1244.130126953125, 0.099917009472846984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Collector Il'zril (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+390, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2114.798583984375, -1158.060791015625, -1244.091064453125, 6.117087364196777343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+391, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2099.953125, -1146.7257080078125, -1242.8306884765625, 1.519499540328979492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+392, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2198.673583984375, -1180.907958984375, -1241.3525390625, 2.58857131004333496, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+393, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2111.505126953125, -1158.6129150390625, -1244.0208740234375, 2.843271732330322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+394, 222538, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2191.204833984375, -1167.9288330078125, -1241.348388671875, 1.401632905006408691, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Loyal Attendant (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+395, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2112.017333984375, -1155.4097900390625, -1244.130126953125, 4.55327463150024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+396, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2118.38720703125, -1151.2535400390625, -1243.2724609375, 1.340652346611022949, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+397, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2113.744873046875, -1147.0035400390625, -1242.661865234375, 3.091448545455932617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+398, 220353, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2025.0504150390625, -1125.3507080078125, -1259.9271240234375, 1.912977933883666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Umbral Citizen (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 299698 - Permanent Feign Death)
(@CGUID+399, 230063, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2115.92041015625, -1140.074951171875, -1244.185546875, 0.157780706882476806, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ax'ill (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+400, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2168.3681640625, -1131.53125, -1244.129150390625, 2.211015939712524414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+401, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2200.0556640625, -1177.328125, -1241.3525390625, 4.951815605163574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+402, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2167.397705078125, -1129.5382080078125, -1244.128173828125, 2.461416482925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+403, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2157.255126953125, -1165.013916015625, -1244.06298828125, 0.675461828708648681, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+404, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2211.5087890625, -1176.15283203125, -1241.3121337890625, 2.745917320251464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+405, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2171.467041015625, -1130.48095703125, -1244.1304931640625, 1.856104850769042968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+406, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2155.046875, -1163.9375, -1244.05029296875, 3.595151424407958984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+407, 223208, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2167.098876953125, -1126.7135009765625, -1244.12841796875, 3.081476449966430664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Favored Novice (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+408, 229793, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2174.1181640625, -1123.9149169921875, -1242.932373046875, 5.509257316589355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Dark Proselityzer (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+409, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2211.032958984375, -1171.375, -1241.3121337890625, 3.606858491897583007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+410, 220004, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2218.460205078125, -1173.2916259765625, -1241.31494140625, 0.191932946443557739, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Ascended Aristocrat (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+411, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2132.015625, -1134.4913330078125, -1244.1304931640625, 0.067441359162330627, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 441952 - Unseen Disguise)
(@CGUID+412, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2196.600830078125, -1247.41845703125, -1239.642822265625, 3.076747894287109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+413, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2156.0625, -1146.9166259765625, -1244.1226806640625, 2.232981204986572265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+414, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2157.572998046875, -1144.9791259765625, -1244.1220703125, 5.59804534912109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+415, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2183.132080078125, -1178.88720703125, -1241.3525390625, 1.884352087974548339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+416, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2189.78125, -1162.8836669921875, -1241.3525390625, 3.451185464859008789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+417, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2201.829833984375, -1180.1475830078125, -1241.3525390625, 0.878569364547729492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+418, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2199.7119140625, -1245.953125, -1239.642822265625, 5.525959968566894531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+419, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2192.875, -1163.873291015625, -1241.3525390625, 6.273410320281982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+420, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2192.138916015625, -1150.1822509765625, -1239.2691650390625, 0.633333802223205566, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+421, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2218.348876953125, -1242.935791015625, -1239.642822265625, 5.715798854827880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+422, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2214.376708984375, -1169.8160400390625, -1241.3121337890625, 4.732563972473144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+423, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2188.84716796875, -1150.734375, -1239.2691650390625, 2.975409746170043945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+424, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2217.98095703125, -1245.6302490234375, -1239.642822265625, 1.051453828811645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+425, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2215.546875, -1177.59033203125, -1241.3123779296875, 1.601090312004089355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+426, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2189.357666015625, -1147.53125, -1239.2691650390625, 4.55327463150024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds)
(@CGUID+427, 220037, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 1, -2240.9775390625, -1259.9305419921875, -1238.8338623046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Reposing Knight (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 446381 - [DNT] Toxic Fumes Proximity Warning)
(@CGUID+428, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2226.40966796875, -1295.6614990234375, -1239.642822265625, 5.374495506286621093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo)
(@CGUID+429, 219983, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2224.8994140625, -1297.5989990234375, -1239.642822265625, 2.232903003692626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hollows Resident (Area: High Hollows - Difficulty: Follower) CreateObject1 (Auras: 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+430, 221003, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2272.328125, -1268.4444580078125, -1184.8822021484375, 5.221925258636474609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Stalker (Area: High Hollows - Difficulty: Follower) CreateObject1
(@CGUID+431, 222013, 2669, 14979, 15112, '1,2,8,23', 0, 0, 0, 0, -2228.76220703125, -1344.27783203125, -1196.112060546875, 5.227909088134765625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56819); -- [DNT] Web Barrier Target (Area: High Hollows - Difficulty: Follower) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+431;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449529'), -- [DNT]Cosmetic Flavor - 449529 - [DNT]Cosmetic Flavor
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '446381'), -- Umbral Citizen - 446381 - [DNT] Toxic Fumes Proximity Warning
(@CGUID+3, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+4, 0, 0, 9, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449509'), -- Favored Citizen - 449509 - Submerge
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Xeph'itik
(@CGUID+7, 0, 0, 9, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449509'), -- Favored Citizen - 449509 - Submerge
(@CGUID+9, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422357'), -- Path Helper - 422357 - Bot AI Follow Advert
(@CGUID+13, 0, 0, 9, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449509'), -- Favored Citizen - 449509 - Submerge
(@CGUID+14, 0, 0, 9, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449509'), -- Favored Citizen - 449509 - Submerge
(@CGUID+16, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+24, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 462571'), -- Hollows Resident - 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Hollows Merchant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Hollows Merchant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '446381'), -- Hollows Merchant - 446381 - [DNT] Toxic Fumes Proximity Warning
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+61, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '441951'), -- Pale Priest - 441951 - Keen Senses
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ascended Aristocrat - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+73, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- Van'atka
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Hollows Merchant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+84, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452338 452885'), -- Kobyss Puppet - 452338 - [DNT] Kobyss Pause Animation, 452885 - [DNT] Puppet
(@CGUID+85, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+87, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Hollows Merchant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+91, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Favored Citizen
(@CGUID+92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441952'), -- Hollows Resident - 455385 - Pheromone Clouds, 441952 - Unseen Disguise
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441838'), -- Hollows Resident - 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441838'), -- Hollows Resident - 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+103, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Assistant Vi
(@CGUID+105, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+111, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Assistant Tix'ii
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Attendant Xeren
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462571'), -- Hollows Merchant - 462571 - [DNT] High Hollows NPC Convo Proximity
(@CGUID+119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '453055'), -- Ozrin the Steelweaver - 453055 - Working
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Hollows Merchant
(@CGUID+124, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ascended Aristocrat - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Hollows Merchant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+144, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Attendant Ak'lii
(@CGUID+147, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+149, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Favored Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+152, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- Profiteer Ri'za
(@CGUID+154, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+157, 0, 0, 0, 0, 0, 1, 0, 0, 6468, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 0, 6468, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 0, 6468, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+169, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '441951'), -- Pale Priest - 441951 - Keen Senses
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+173, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '455385 323849'), -- Dark Proselityzer - 455385 - Pheromone Clouds, 323849 - Shadow Channeling
(@CGUID+179, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ascended Aristocrat - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441838'), -- Hollows Resident - 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book
(@CGUID+186, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+187, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+190, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+195, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 455405'), -- Hollows Resident - 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM)
(@CGUID+201, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+202, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 455405'), -- Hollows Resident - 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM)
(@CGUID+204, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 455405'), -- Hollows Resident - 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM)
(@CGUID+205, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+208, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 455405'), -- Hollows Resident - 455385 - Pheromone Clouds, 455405 - [DNT] Generic - RP - General Trigger: 32 - Area Trigger (ELM)
(@CGUID+220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ascended Aristocrat
(@CGUID+230, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Assistant Tik
(@CGUID+236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+239, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+240, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441952'), -- Hollows Resident - 455385 - Pheromone Clouds, 441952 - Unseen Disguise
(@CGUID+244, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+252, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+253, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 393603'), -- Hollows Resident - 455385 - Pheromone Clouds, 393603 - Cosmetic - Reading Book, Standing
(@CGUID+259, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '455385 393603'), -- Hollows Resident - 455385 - Pheromone Clouds, 393603 - Cosmetic - Reading Book, Standing
(@CGUID+260, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 393603'), -- Hollows Resident - 455385 - Pheromone Clouds, 393603 - Cosmetic - Reading Book, Standing
(@CGUID+261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+262, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+263, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+265, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+266, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Venomscribe Xesh XI
(@CGUID+267, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+268, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Reposing Knight
(@CGUID+290, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 462571'), -- Hollows Resident - 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity
(@CGUID+295, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ascended Aristocrat - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+302, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+305, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 462571'), -- Hollows Resident - 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity
(@CGUID+306, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+307, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+312, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+315, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441838'), -- Hollows Resident - 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book
(@CGUID+317, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Royal Journalist Ist'iix - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462571'), -- Favored Citizen - 462571 - [DNT] High Hollows NPC Convo Proximity
(@CGUID+331, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+339, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441952'), -- Hollows Resident - 455385 - Pheromone Clouds, 441952 - Unseen Disguise
(@CGUID+341, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441838'), -- Hollows Resident - 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book
(@CGUID+342, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441838'), -- Hollows Resident - 455385 - Pheromone Clouds, 441838 - Cosmetic - Reading Book
(@CGUID+343, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '423679'), -- Izo, the Grand Splicer - 423679 - Bot AI Follow Advert
(@CGUID+348, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+352, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+359, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+360, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+362, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+363, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+364, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+365, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 462571'), -- Hollows Resident - 455385 - Pheromone Clouds, 462571 - [DNT] High Hollows NPC Convo Proximity
(@CGUID+368, 0, 0, 0, 0, 0, 1, 0, 0, 6468, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+370, 0, 0, 0, 0, 0, 1, 0, 0, 6468, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+372, 0, 0, 0, 0, 0, 1, 0, 0, 6468, 0, 0, 0, '455385 434103'), -- Hollows Resident - 455385 - Pheromone Clouds, 434103 - Conversation Aura - Sitting: Talk/Point/Question/Yes/No/Cry/Cheer [DNT]
(@CGUID+374, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+376, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Reposing Knight - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+377, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Tulumun - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+383, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Favored Citizen
(@CGUID+384, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+387, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459879 371815'), -- Favored Citizen - 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+389, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Collector Il'zril
(@CGUID+390, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+391, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+394, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Loyal Attendant - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+396, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+397, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Hollows Resident - 455385 - Pheromone Clouds
(@CGUID+398, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '299698'), -- Umbral Citizen - 299698 - Permanent Feign Death
(@CGUID+400, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Favored Novice - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+402, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+404, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '459879'), -- Ascended Aristocrat - 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+405, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+406, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+407, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- Favored Novice - 455385 - Pheromone Clouds
(@CGUID+409, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '459879 371815'), -- Ascended Aristocrat - 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '459879'), -- Ascended Aristocrat - 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+411, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 441952'), -- Hollows Resident - 455385 - Pheromone Clouds, 441952 - Unseen Disguise
(@CGUID+413, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+415, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+416, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+422, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+423, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 371815'), -- Hollows Resident - 455385 - Pheromone Clouds, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+425, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '446381'), -- Reposing Knight - 446381 - [DNT] Toxic Fumes Proximity Warning
(@CGUID+428, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879'), -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo
(@CGUID+429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385 459879 371815'); -- Hollows Resident - 455385 - Pheromone Clouds, 459879 - [DNT] High Hollows Proximity Convo, 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (216658 /*216658 (Izo, the Grand Splicer) - Bot AI Follow Advert*/, 220404 /*220404 (Royal Acolyte) - Pheromone Clouds*/, 223202 /*223202 (Beetle of Burden) - Ride Vehicle Hardcoded*/, 226053 /*226053 (Assistant Ulo'vix)*/, 226057 /*226057 (Earthen Puppet) - [DNT] Earthen Pause Animation, [DNT] Puppet*/, 226060 /*226060 (Kobyss Puppet) - [DNT] Kobyss Pause Animation, [DNT] Puppet*/, 225141 /*225141 ([DNT] Web Bunny) - Ride Vehicle Hardcoded, [DNT] Web Orb*/, 226789 /*226789 (Tulumun) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]*/, 222538 /*222538 (Loyal Attendant) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]*/, 220423 /*220423 (Retired Lord Vul'azak) - Invisibility and Stealth Detection*/, 220037 /*220037 (Reposing Knight) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]*/, 229793 /*229793 (Dark Proselityzer) - Pheromone Clouds*/, 230056 /*230056 (Assistant Ven'ik)*/, 219984 /*219984 (Xeph'itik)*/, 225167 /*225167 (ELM General Purpose Bunny - Flying (scale x0.01))*/, 223208 /*223208 (Favored Novice) - Pheromone Clouds*/, 226064 /*226064 (Ozrin the Steelweaver) - Working*/, 220793 /*220793 (Favored Citizen) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]*/, 220012 /*220012 (Hollows Merchant) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]*/, 220401 /*220401 (Pale Priest) - Keen Senses*/, 209059 /*209059 (Meredy Huntswell) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Cloth, Proc, Scale, AI Buff Watcher, Mastery: Ignite, Bot AI Follow Advert, Pheromone Veil*/, 209057 /*209057 (Captain Garrick) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Plate, Proc, Scale, AI Buff Watcher, Bot AI Follow Advert, Devotion Aura, Devotion Aura, Mounted, Pheromone Veil, Mount Speed Mod: Epic Ground Mount*/, 220004 /*220004 (Ascended Aristocrat)*/, 223771 /*223771 ([DNT]Cosmetic Flavor) - [DNT]Cosmetic Flavor*/, 214390 /*214390 (Shuja Grimaxe) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Mail, Proc, Scale, AI Buff Watcher, Bot AI Follow Advert, Mounted, Pheromone Veil, Mount Speed Mod: Epic Ground Mount*/, 209072 /*209072 (Crenna Earth-Daughter) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Leather, Proc, Scale, AI Buff Watcher, Ysera's Gift, Bot AI Follow Advert, Pheromone Veil*/, 219983 /*219983 (Hollows Resident) - Pheromone Clouds, [DNT] High Hollows NPC Convo Proximity*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(216658, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '423679'), -- 216658 (Izo, the Grand Splicer) - Bot AI Follow Advert
(220404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- 220404 (Royal Acolyte) - Pheromone Clouds
(223202, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 223202 (Beetle of Burden) - Ride Vehicle Hardcoded
(226053, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226053 (Assistant Ulo'vix)
(226057, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452345 452885'), -- 226057 (Earthen Puppet) - [DNT] Earthen Pause Animation, [DNT] Puppet
(226060, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452338 452885'), -- 226060 (Kobyss Puppet) - [DNT] Kobyss Pause Animation, [DNT] Puppet
(225141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452996'), -- 225141 ([DNT] Web Bunny) - Ride Vehicle Hardcoded, [DNT] Web Orb
(226789, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226789 (Tulumun) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(222538, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222538 (Loyal Attendant) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(220423, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 220423 (Retired Lord Vul'azak) - Invisibility and Stealth Detection
(220037, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 220037 (Reposing Knight) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(229793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '455385'), -- 229793 (Dark Proselityzer) - Pheromone Clouds
(230056, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 230056 (Assistant Ven'ik)
(219984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 219984 (Xeph'itik)
(225167, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 225167 (ELM General Purpose Bunny - Flying (scale x0.01))
(223208, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'), -- 223208 (Favored Novice) - Pheromone Clouds
(226064, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '453055'), -- 226064 (Ozrin the Steelweaver) - Working
(220793, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220793 (Favored Citizen) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(220012, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220012 (Hollows Merchant) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(220401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '441951'), -- 220401 (Pale Priest) - Keen Senses
(220004, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 220004 (Ascended Aristocrat)
(223771, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '449529'), -- 223771 ([DNT]Cosmetic Flavor) - [DNT]Cosmetic Flavor
(219983, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '455385'); -- 219983 (Hollows Resident) - Pheromone Clouds, [DNT] High Hollows NPC Convo Proximity

-- Template
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1073741825, `flags_extra` = 128 WHERE `entry` IN (221003, 226177, 223716); -- Stalker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230063; -- Ax'ill
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=226063; -- Collector Il'zril
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=226789; -- Tulumun
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1073741825, `flags_extra` = 128 WHERE `entry`=222013; -- [DNT] Web Barrier Target
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=832 WHERE `entry`=216658; -- Izo, the Grand Splicer
UPDATE `creature_template` SET `faction`=190, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=227607; -- Fliq'ri
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=227613; -- Skitterling
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=227612; -- Spider
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230067; -- Royal Journalist Ist'iix
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230065; -- Venomscribe Xesh XI
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=226056; -- Collector Z'til
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230066; -- Assistant Tik
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry` IN (229682, 229684, 229681, 229680); -- Path Helper
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230053; -- Profiteer Xir'ek
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=226055; -- Profiteer Z'kaxt
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67176448, `unit_flags3`=16777217, `VehicleId`=8517 WHERE `entry`=223203; -- Skittershaw
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=67176448, `unit_flags3`=83918849 WHERE `entry`=223202; -- Beetle of Burden
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220409; -- Zeki
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230052; -- Profiteer Ri'za
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220408; -- Kiki
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220407; -- Silki
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230051; -- Attendant Ak'lii
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220404; -- Royal Acolyte
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230048; -- Xir'ra
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `flags_extra` = 128 WHERE `entry`=225167; -- ELM General Purpose Bunny - Flying (scale x0.01)
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=226064; -- Ozrin the Steelweaver
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230050; -- Attendant Xeren
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230054; -- Assistant Tix'ii
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220037; -- Reposing Knight
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230049; -- Assistant Vi
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=223208; -- Favored Novice
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226053; -- Assistant Ulo'vix
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1073741824, `flags_extra` = 128 WHERE `entry`=225141; -- [DNT] Web Bunny
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1090519041, `VehicleId`=8573 WHERE `entry`=226057; -- Earthen Puppet
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1090519041, `VehicleId`=8573 WHERE `entry`=226060; -- Kobyss Puppet
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230047; -- Q'ilax
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=226058; -- Van'atka
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=229793; -- Dark Proselityzer
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220423; -- Retired Lord Vul'azak
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=222538; -- Loyal Attendant
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=230056; -- Assistant Ven'ik
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220004; -- Ascended Aristocrat
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220012; -- Hollows Merchant
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220401; -- Pale Priest
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=219983; -- Hollows Resident
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=220793; -- Favored Citizen
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040, `flags_extra` = 128 WHERE `entry`=223771; -- [DNT]Cosmetic Flavor

DELETE FROM `gameobject_template` WHERE `entry`=453608;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(453608, 19, 92411, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56819); -- Mailbox

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry` IN (223203,226060,226057)) OR (`seat_id`=1 AND `entry`=223203);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(223203, 223202, 0, 0, 'Skittershaw - Beetle of Burden', 8, 0), -- Skittershaw - Beetle of Burden
(223203, 220004, 1, 0, 'Skittershaw - Ascended Aristocrat', 8, 0), -- Skittershaw - Ascended Aristocrat
(226060, 225141, 0, 0, 'Kobyss Puppet - [DNT] Web Bunny', 8, 0), -- Kobyss Puppet - [DNT] Web Bunny
(226057, 225141, 0, 0, 'Earthen Puppet - [DNT] Web Bunny', 8, 0); -- Earthen Puppet - [DNT] Web Bunny

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (223203, 226060, 226057);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(223203, 46598, 1, 0),
(226060, 46598, 1, 0),
(226057, 46598, 1, 0);

-- Path for Assistant Venik
SET @MOVERGUID := @CGUID+47;
SET @ENTRY := 230056;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Assistant Ven''ik - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2053.8044, -1183.5656, -1244.2147, NULL, 0),
(@PATH, 1, -2036.74, -1184.47, -1244.2147, NULL, 21126),
(@PATH, 2, -2053.8044, -1183.5656, -1244.2147, NULL, 0),
(@PATH, 3, -2073.961, -1192.3141, -1244.2147, NULL, 0),
(@PATH, 4, -2074.29, -1197.86, -1243.6381, NULL, 10261);

UPDATE `creature` SET `position_x`=-2053.8044, `position_y`=-1183.5656, `position_z`=-1244.2147, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Favored Novice
SET @MOVERGUID := @CGUID+163;
SET @ENTRY := 223208;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Favored Novice - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2151.041, -1240.35, -1244.1853, NULL, 7688),
(@PATH, 1, -2140.71, -1225, -1244.19, NULL, 291),
(@PATH, 2, -2125.357, -1216.261, -1244.1864, NULL, 0),
(@PATH, 3, -2077.1128, -1239.3877, -1244.183, NULL, 0),
(@PATH, 4, -2054.557, -1242.8784, -1244.1722, NULL, 0),
(@PATH, 5, -2033.8877, -1221.4342, -1244.1482, NULL, 0),
(@PATH, 6, -2018.4719, -1230.468, -1244.0215, NULL, 10372),
(@PATH, 7, -2038.3251, -1213.6384, -1244.134, NULL, 0),
(@PATH, 8, -2070.3433, -1183.1614, -1244.2147, NULL, 0),
(@PATH, 9, -2061.5789, -1163.4172, -1244.2147, NULL, 0),
(@PATH, 10, -2057.92, -1154.83, -1243.2246, NULL, 11344),
(@PATH, 11, -2081.1816, -1177.0068, -1244.2147, NULL, 0),
(@PATH, 12, -2100.308, -1185.5289, -1244.2147, NULL, 0),
(@PATH, 13, -2119.861, -1181.404, -1244.2065, NULL, 0),
(@PATH, 14, -2130.8162, -1191.2782, -1244.0782, NULL, 0),
(@PATH, 15, -2148.1912, -1219.645, -1244.1304, NULL, 0),
(@PATH, 16, -2162.633, -1233.0825, -1241.4297, NULL, 0);

UPDATE `creature` SET `position_x`=-2151.041, `position_y`=-1240.35, `position_z`=-1244.1853, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '455385');

-- Path for Favored Novice
SET @MOVERGUID := @CGUID+99;
SET @ENTRY := 223208;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Favored Novice - Comsetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1992.37, -1410.96, -1244.1853, NULL, 13254),
(@PATH, 1, -1978.6647, -1393.1594, -1244.1853, NULL, 0),
(@PATH, 2, -1975.7494, -1374.12, -1244.1853, NULL, 0),
(@PATH, 3, -1986.49, -1375.06, -1244.1853, NULL, 10509),
(@PATH, 4, -1969.1702, -1364.6665, -1244.1853, NULL, 0),
(@PATH, 5, -1932.7471, -1346.46, -1244.1853, NULL, 0),
(@PATH, 6, -1925.9, -1357.87, -1244.1853, NULL, 9496),
(@PATH, 7, -1932.7471, -1346.46, -1244.1853, NULL, 0),
(@PATH, 8, -1969.0344, -1364.8927, -1244.1853, NULL, 0),
(@PATH, 9, -1978.8475, -1396.5669, -1244.1853, NULL, 0),
(@PATH, 10, -1980.5758, -1413.2839, -1244.1853, NULL, 0);

UPDATE `creature` SET `position_x`=-1992.37, `position_y`=-1410.96, `position_z`=-1244.1853, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '455385');

-- Path for Favored Novice
SET @MOVERGUID := @CGUID+297;
SET @ENTRY := 223208;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Favored Novice - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2094.67, -1520.81, -1239.7262, NULL, 12034),
(@PATH, 1, -2126.1143, -1526.8163, -1239.7262, NULL, 0),
(@PATH, 2, -2139.984, -1553.4493, -1239.7262, NULL, 0),
(@PATH, 3, -2143.52, -1560.72, -1239.6151, NULL, 11361),
(@PATH, 4, -2154.9504, -1520.064, -1239.7262, NULL, 0),
(@PATH, 5, -2166.2253, -1530.9348, -1239.7262, NULL, 0),
(@PATH, 6, -2199.7646, -1525.2395, -1239.7262, NULL, 0),
(@PATH, 7, -2195.2178, -1551.1981, -1239.2811, NULL, 0),
(@PATH, 8, -2199.0461, -1569.8955, -1245.924, NULL, 0),
(@PATH, 9, -2192.9905, -1595.8043, -1246.5555, NULL, 0),
(@PATH, 10, -2192.06, -1602.08, -1246.5463, NULL, 10787),
(@PATH, 11, -2194.9802, -1568.8809, -1246.5092, NULL, 0),
(@PATH, 12, -2195.197, -1551.3718, -1239.4178, NULL, 0),
(@PATH, 13, -2196.0273, -1521.9535, -1239.7262, NULL, 0),
(@PATH, 14, -2168.3845, -1531.2935, -1239.7262, NULL, 0),
(@PATH, 15, -2150.3796, -1521.8689, -1239.7262, NULL, 0),
(@PATH, 16, -2097.4297, -1492.521, -1239.7262, NULL, 0),
(@PATH, 17, -2088.947, -1498.1394, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2094.67, `position_y`=-1520.81, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '455385');

-- Path for Favored Novice
SET @MOVERGUID := @CGUID+327;
SET @ENTRY := 223208;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Favored Novice - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2226.492, -1512.4117, -1239.7262, NULL, 0),
(@PATH, 1, -2248.7358, -1494.697, -1238.8184, NULL, 0),
(@PATH, 2, -2282.1577, -1475.0935, -1254.4121, NULL, 0),
(@PATH, 3, -2296.5115, -1480.1973, -1255.6862, NULL, 0),
(@PATH, 4, -2298.76, -1488.03, -1255.6173, NULL, 12280),
(@PATH, 5, -2280.7822, -1475.369, -1254.4121, NULL, 0),
(@PATH, 6, -2248.7114, -1494.7115, -1238.8184, NULL, 0),
(@PATH, 7, -2226.492, -1512.4117, -1239.7262, NULL, 0),
(@PATH, 8, -2237.74, -1531.02, -1239.6154, NULL, 24002);

UPDATE `creature` SET `position_x`=-2226.492, `position_y`=-1512.4117, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '455385');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+20;
SET @ENTRY := 220401;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2034.8936, -1209.5905, -1244.1772, NULL, 0),
(@PATH, 1, -2077.2778, -1191.3417, -1244.2147, NULL, 0),
(@PATH, 2, -2105.886, -1204.5474, -1244.2147, NULL, 0),
(@PATH, 3, -2107.08, -1206.45, -1244.2147, NULL, 14),
(@PATH, 4, -2079.54, -1187.67, -1244.2147, NULL, 9),
(@PATH, 5, -2034.8936, -1209.5905, -1244.1772, NULL, 0),
(@PATH, 6, -2011.72, -1196.68, -1243.8184, NULL, 31679);

UPDATE `creature` SET `position_x`=-2034.8936, `position_y`=-1209.5905, `position_z`=-1244.1772, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+45;
SET @ENTRY := 220401;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2106.3281, -1206.0491, -1244.2147, NULL, 0),
(@PATH, 1, -2107.08, -1206.45, -1244.2147, NULL, 0),
(@PATH, 2, -2079.54, -1187.67, -1244.2147, NULL, 0),
(@PATH, 3, -2034.8936, -1209.5905, -1244.1772, NULL, 0),
(@PATH, 4, -2011.72, -1196.68, -1243.8184, NULL, 15917),
(@PATH, 5, -2033.3983, -1220.5005, -1244.1473, NULL, 0),
(@PATH, 6, -2055.913, -1237.1598, -1244.1715, NULL, 0),
(@PATH, 7, -2069.7632, -1256.9106, -1244.1847, NULL, 0),
(@PATH, 8, -2075.11, -1263.99, -1244.1853, NULL, 15434),
(@PATH, 9, -2077.5105, -1239.9344, -1244.1826, NULL, 0),
(@PATH, 10, -2100.0862, -1220.281, -1244.2147, NULL, 0),
(@PATH, 11, -2102.5388, -1208.0118, -1244.2147, NULL, 0);

UPDATE `creature` SET `position_x`=-2106.3281, `position_y`=-1206.0491, `position_z`=-1244.2147, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+50;
SET @ENTRY := 220401;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1949.3785, -1344.118, -1244.2056, NULL, 0),
(@PATH, 1, -1956.9219, -1358.0834, -1244.1853, NULL, 0),
(@PATH, 2, -1969.8993, -1358.7709, -1244.1853, NULL, 0),
(@PATH, 3, -1980.5938, -1347.849, -1244.1853, NULL, 0),
(@PATH, 4, -1979.6442, -1331.2014, -1244.1853, NULL, 0),
(@PATH, 5, -1967.7743, -1323.4548, -1244.1853, NULL, 0),
(@PATH, 6, -1951.7916, -1333.3889, -1244.2147, NULL, 0);

UPDATE `creature` SET `position_x`=-1949.3785, `position_y`=-1344.118, `position_z`=-1244.2056, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951');

-- Path for Pale Priest
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+93;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+93, @CGUID+93, 0, 0, 515, 7, 44),
(@CGUID+93, @CGUID+264, 3, 90, 515, 7, 44);

SET @MOVERGUID := @CGUID+93;
SET @ENTRY := 220401;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2088.9028, -1492.8373, -1239.7262, NULL, 0),
(@PATH, 1, -2085.8682, -1492.8597, -1239.7262, NULL, 0),
(@PATH, 2, -2082.8386, -1492.8821, -1239.7262, NULL, 0),
(@PATH, 3, -2080.6616, -1492.6974, -1239.7262, NULL, 0),
(@PATH, 4, -2077.8782, -1491.5603, -1239.7262, NULL, 0),
(@PATH, 5, -2076.5007, -1490.253, -1239.7262, NULL, 0),
(@PATH, 6, -2075.0999, -1488.4719, -1239.7262, NULL, 0),
(@PATH, 7, -2075.0999, -1488.4719, -1239.7262, NULL, 15022),
(@PATH, 8, -2078.0876, -1490.1726, -1239.7262, NULL, 0),
(@PATH, 9, -2080.931, -1489.1346, -1239.7262, NULL, 0),
(@PATH, 10, -2083.7778, -1488.0951, -1239.7262, NULL, 0),
(@PATH, 11, -2086.2534, -1487.9672, -1239.7262, NULL, 0),
(@PATH, 12, -2088.769, -1488.093, -1239.7262, NULL, 0),
(@PATH, 13, -2091.7354, -1488.6141, -1239.7262, NULL, 0),
(@PATH, 14, -2094.5867, -1489.2339, -1239.7262, NULL, 0),
(@PATH, 15, -2097.4705, -1489.9227, -1239.7262, NULL, 0),
(@PATH, 16, -2100.412, -1490.7268, -1239.7262, NULL, 0),
(@PATH, 17, -2103.243, -1491.522, -1239.7262, NULL, 0),
(@PATH, 18, -2106.1123, -1492.4478, -1239.7262, NULL, 0),
(@PATH, 19, -2108.9958, -1493.378, -1239.7262, NULL, 0),
(@PATH, 20, -2111.8938, -1494.313, -1239.7262, NULL, 0),
(@PATH, 21, -2114.7776, -1495.2433, -1239.7262, NULL, 0),
(@PATH, 22, -2117.2668, -1496.284, -1239.7262, NULL, 0),
(@PATH, 23, -2120.0059, -1497.6022, -1239.7262, NULL, 0),
(@PATH, 24, -2122.7473, -1498.9214, -1239.7262, NULL, 0),
(@PATH, 25, -2125.4866, -1500.2395, -1239.7262, NULL, 0),
(@PATH, 26, -2128.2075, -1501.549, -1239.7262, NULL, 0),
(@PATH, 27, -2130.5874, -1502.9194, -1239.7262, NULL, 0),
(@PATH, 28, -2133.1572, -1504.5298, -1239.7262, NULL, 0),
(@PATH, 29, -2135.742, -1506.1494, -1239.7262, NULL, 0),
(@PATH, 30, -2138.3394, -1507.7771, -1239.7262, NULL, 0),
(@PATH, 31, -2140.92, -1509.394, -1239.7262, NULL, 0),
(@PATH, 32, -2143.518, -1510.9916, -1239.7262, NULL, 0),
(@PATH, 33, -2146.0867, -1512.5542, -1239.7262, NULL, 0),
(@PATH, 34, -2148.6726, -1514.1272, -1239.7262, NULL, 0),
(@PATH, 35, -2151.267, -1515.7054, -1239.7262, NULL, 0),
(@PATH, 36, -2153.857, -1517.2877, -1239.7261, NULL, 0),
(@PATH, 37, -2156.4382, -1518.9022, -1239.7262, NULL, 0),
(@PATH, 38, -2159.0007, -1520.5049, -1239.7262, NULL, 0),
(@PATH, 39, -2161.5757, -1522.1155, -1239.7262, NULL, 0),
(@PATH, 40, -2163.4912, -1523.6184, -1239.7262, NULL, 0),
(@PATH, 41, -2165.5293, -1525.8674, -1239.7262, NULL, 0),
(@PATH, 42, -2167.5776, -1528.1278, -1239.7262, NULL, 0),
(@PATH, 43, -2169.624, -1530.3861, -1239.7262, NULL, 0),
(@PATH, 44, -2170.5337, -1531.3899, -1239.7262, NULL, 9261),
(@PATH, 45, -2168.6523, -1526.9316, -1239.7262, NULL, 0),
(@PATH, 46, -2165.7563, -1526.0494, -1239.7262, NULL, 0),
(@PATH, 47, -2162.8748, -1525.1716, -1239.7263, NULL, 0),
(@PATH, 48, -2159.9595, -1524.2837, -1239.7263, NULL, 0),
(@PATH, 49, -2157.073, -1523.4043, -1239.7262, NULL, 0),
(@PATH, 50, -2154.607, -1522.51, -1239.7262, NULL, 0),
(@PATH, 51, -2151.8792, -1521.1002, -1239.7261, NULL, 0),
(@PATH, 52, -2149.1829, -1519.7065, -1239.7262, NULL, 0),
(@PATH, 53, -2146.5588, -1518.3384, -1239.7262, NULL, 0),
(@PATH, 54, -2143.934, -1516.8596, -1239.7262, NULL, 0),
(@PATH, 55, -2141.3074, -1515.3796, -1239.7262, NULL, 0),
(@PATH, 56, -2138.6804, -1513.8997, -1239.7262, NULL, 0),
(@PATH, 57, -2136.0405, -1512.4124, -1239.7262, NULL, 0),
(@PATH, 58, -2133.394, -1510.9214, -1239.7262, NULL, 0),
(@PATH, 59, -2130.739, -1509.4254, -1239.7262, NULL, 0),
(@PATH, 60, -2128.2307, -1507.9553, -1239.7262, NULL, 0),
(@PATH, 61, -2125.6719, -1506.2827, -1239.7262, NULL, 0),
(@PATH, 62, -2123.1277, -1504.6198, -1239.7262, NULL, 0),
(@PATH, 63, -2120.5774, -1502.9568, -1239.7262, NULL, 0),
(@PATH, 64, -2118.0317, -1501.3279, -1239.7262, NULL, 0),
(@PATH, 65, -2115.467, -1499.6868, -1239.7262, NULL, 0),
(@PATH, 66, -2112.9255, -1498.0604, -1239.7262, NULL, 0),
(@PATH, 67, -2110.1414, -1496.4308, -1239.7262, NULL, 0),
(@PATH, 68, -2107.448, -1495.0374, -1239.7262, NULL, 0),
(@PATH, 69, -2104.3164, -1493.6234, -1239.7262, NULL, 0),
(@PATH, 70, -2101.3943, -1492.8081, -1239.7262, NULL, 0),
(@PATH, 71, -2097.7703, -1492.4514, -1239.7262, NULL, 0),
(@PATH, 72, -2094.7456, -1492.628, -1239.7262, NULL, 0),
(@PATH, 73, -2091.7131, -1492.8053, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2088.9028, `position_y`=-1492.8373, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+57;
SET @ENTRY := 220401;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2057.7493, -1458.9713, -1239.7262, NULL, 0),
(@PATH, 1, -2068.1765, -1455.1774, -1239.7262, NULL, 0),
(@PATH, 2, -2082.3494, -1461.5436, -1239.7262, NULL, 0),
(@PATH, 3, -2110.8362, -1448.9355, -1239.7262, NULL, 0),
(@PATH, 4, -2128.7556, -1456.6016, -1239.7262, NULL, 0),
(@PATH, 5, -2132.27, -1458.1, -1239.7262, NULL, 17984),
(@PATH, 6, -2110.7014, -1448.9192, -1239.7262, NULL, 0),
(@PATH, 7, -2080.7832, -1461.9615, -1239.7262, NULL, 0),
(@PATH, 8, -2069.7852, -1467.6859, -1239.7262, NULL, 0),
(@PATH, 9, -2046.1187, -1460.4556, -1239.7262, NULL, 0),
(@PATH, 10, -2030.8165, -1477.0653, -1239.7262, NULL, 0),
(@PATH, 11, -2032.72, -1479.26, -1239.7262, NULL, 6166);

UPDATE `creature` SET `position_x`=-2057.7493, `position_y`=-1458.9713, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+59;
SET @ENTRY := 220401;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2023.0938, -1389.6459, -1239.7262, NULL, 0),
(@PATH, 1, -2028.6562, -1374.1632, -1239.7262, NULL, 0),
(@PATH, 2, -2036.1754, -1365.8993, -1239.7262, NULL, 0),
(@PATH, 3, -2047.7118, -1357.0851, -1239.7262, NULL, 0),
(@PATH, 4, -2069.8784, -1341.132, -1239.7262, NULL, 0),
(@PATH, 5, -2087.8455, -1343.5764, -1239.7262, NULL, 0),
(@PATH, 6, -2109.3801, -1374.6285, -1239.7262, NULL, 0),
(@PATH, 7, -2115.467, -1392.6216, -1239.7262, NULL, 0),
(@PATH, 8, -2115.3298, -1413.849, -1239.7262, NULL, 0),
(@PATH, 9, -2104.9548, -1431.5747, -1239.7262, NULL, 0),
(@PATH, 10, -2084.9426, -1450.0781, -1239.7262, NULL, 0),
(@PATH, 11, -2059.3315, -1452.2327, -1239.7262, NULL, 0),
(@PATH, 12, -2041.5104, -1440.7153, -1239.7262, NULL, 0),
(@PATH, 13, -2036.5608, -1430.0504, -1239.7262, NULL, 0),
(@PATH, 14, -2023.0868, -1415.6129, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2023.0938, `position_y`=-1389.6459, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951 441664');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+63;
SET @ENTRY := 220401;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2036.5608, -1430.0504, -1239.7262, NULL, 0),
(@PATH, 1, -2023.0868, -1415.6129, -1239.7262, NULL, 0),
(@PATH, 2, -2023.0938, -1389.6459, -1239.7262, NULL, 0),
(@PATH, 3, -2028.6562, -1374.1632, -1239.7262, NULL, 0),
(@PATH, 4, -2036.1754, -1365.8993, -1239.7262, NULL, 0),
(@PATH, 5, -2047.7118, -1357.0851, -1239.7262, NULL, 0),
(@PATH, 6, -2069.8784, -1341.132, -1239.7262, NULL, 0),
(@PATH, 7, -2087.8455, -1343.5764, -1239.7262, NULL, 0),
(@PATH, 8, -2109.3801, -1374.6285, -1239.7262, NULL, 0),
(@PATH, 9, -2115.467, -1392.6216, -1239.7262, NULL, 0),
(@PATH, 10, -2115.3298, -1413.849, -1239.7262, NULL, 0),
(@PATH, 11, -2104.9548, -1431.5747, -1239.7262, NULL, 0),
(@PATH, 12, -2084.9426, -1450.0781, -1239.7262, NULL, 0),
(@PATH, 13, -2059.3315, -1452.2327, -1239.7262, NULL, 0),
(@PATH, 14, -2041.5104, -1440.7153, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2036.5608, `position_y`=-1430.0504, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951 441664');

-- Path for Pale Priest
SET @MOVERGUID := @CGUID+64;
SET @ENTRY := 220401;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Pale Priest - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2121.912, -1346.5308, -1239.7262, NULL, 0),
(@PATH, 1, -2133.36, -1344.73, -1239.7262, NULL, 13624),
(@PATH, 2, -2108.3755, -1331.3044, -1239.7262, NULL, 0),
(@PATH, 3, -2107.8127, -1308.8776, -1239.7262, NULL, 0),
(@PATH, 4, -2179.757, -1260.5651, -1239.7262, NULL, 0),
(@PATH, 5, -2213.7292, -1251.6082, -1239.7262, NULL, 0),
(@PATH, 6, -2214.51, -1245.98, -1239.7262, NULL, 14467),
(@PATH, 7, -2184.016, -1272.0859, -1239.7262, NULL, 0),
(@PATH, 8, -2105.273, -1314.351, -1239.7262, NULL, 0),
(@PATH, 9, -2109.0342, -1332.5286, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2121.912, `position_y`=-1346.5308, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '441951');

-- Path for Favored Citizen
SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 220793;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Favored Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1943.49, -1368.1, -1244.1853, NULL, 9583),
(@PATH, 1, -1966.5051, -1361.5182, -1244.1853, NULL, 0),
(@PATH, 2, -1985.0087, -1346.368, -1244.1853, NULL, 0),
(@PATH, 3, -1980.2366, -1315.9777, -1244.1853, NULL, 0),
(@PATH, 4, -1996.7726, -1295.0603, -1239.4933, NULL, 0),
(@PATH, 5, -2018.8872, -1275.8524, -1239.7262, NULL, 0),
(@PATH, 6, -2026.2423, -1265.3777, -1239.1149, NULL, 0),
(@PATH, 7, -2055.0364, -1237.7535, -1244.1702, NULL, 4797),
(@PATH, 8, -2046.2693, -1211.785, -1244.1835, NULL, 11968),
(@PATH, 9, -2051.475, -1240.165, -1244.1761, NULL, 0),
(@PATH, 10, -2026.2423, -1265.3773, -1239.1151, NULL, 0),
(@PATH, 11, -2021.7747, -1277.8064, -1239.7262, NULL, 0),
(@PATH, 12, -1997.6641, -1295.961, -1239.3783, NULL, 0),
(@PATH, 13, -1975.7462, -1314.8176, -1244.1853, NULL, 0),
(@PATH, 14, -1982.7745, -1346.9183, -1244.1853, NULL, 0),
(@PATH, 15, -1966.5051, -1361.5182, -1244.1853, NULL, 0);

UPDATE `creature` SET `position_x`=-1943.49, `position_y`=-1368.1, `position_z`=-1244.1853, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Favored Citizen
SET @MOVERGUID := @CGUID+175;
SET @ENTRY := 220793;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Favored Citizen - Cosmetic');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2201.49, -1238.63, -1239.7262, NULL, 10932),
(@PATH, 1, -2174.9595, -1260.7909, -1239.7262, NULL, 0),
(@PATH, 2, -2104.9685, -1313.8232, -1239.7262, NULL, 0),
(@PATH, 3, -2058.8218, -1329.9507, -1239.7262, NULL, 0),
(@PATH, 4, -2031.0446, -1301.7933, -1239.7262, NULL, 0),
(@PATH, 5, -2014.0515, -1279.892, -1239.7262, NULL, 0),
(@PATH, 6, -1997.6641, -1295.961, -1239.3783, NULL, 0),
(@PATH, 7, -1979.6115, -1318.3977, -1244.1853, NULL, 0),
(@PATH, 8, -1987.2428, -1345.8177, -1244.1853, NULL, 0),
(@PATH, 9, -1972.23, -1366.5195, -1244.1853, NULL, 0),
(@PATH, 10, -1978.0044, -1396.4932, -1244.1853, NULL, 0),
(@PATH, 11, -1979.9598, -1416.1796, -1244.1853, NULL, 0),
(@PATH, 12, -1983.33, -1417.41, -1244.1853, NULL, 11923),
(@PATH, 13, -1977.8342, -1393.323, -1244.1853, NULL, 0),
(@PATH, 14, -1973.1134, -1364.4454, -1244.1853, NULL, 0),
(@PATH, 15, -1986.7415, -1347.8818, -1244.1853, NULL, 0),
(@PATH, 16, -1980.2366, -1315.9777, -1244.1853, NULL, 0),
(@PATH, 17, -1997.6423, -1295.9834, -1239.3922, NULL, 0),
(@PATH, 18, -2014.6538, -1271.1855, -1239.7261, NULL, 0),
(@PATH, 19, -2042.2056, -1292.3784, -1239.7262, NULL, 0),
(@PATH, 20, -2063.9626, -1314.3223, -1239.7262, NULL, 0),
(@PATH, 21, -2101.598, -1305.2965, -1239.7262, NULL, 0),
(@PATH, 22, -2180.3079, -1261.5201, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2201.49, `position_y`=-1238.63, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Retired Lord Vulazak
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+62;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+62, @CGUID+62, 0, 0, 515, 0, 0),
(@CGUID+62, @CGUID+148, 10, 90, 515, 9, 0),
(@CGUID+62, @CGUID+150, 10, 140, 515, 9, 0),
(@CGUID+62, @CGUID+156, 10, 220, 515, 9, 0);

SET @MOVERGUID := @CGUID+62;
SET @ENTRY := 220423;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Retired Lord Vul''azak - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2076.5312, -1301.7955, -1239.7262, NULL, 11281),
(@PATH, 1, -2068.1113, -1322.3813, -1239.7262, NULL, 0),
(@PATH, 2, -2054.297, -1354.324, -1239.7262, NULL, 0),
(@PATH, 3, -2039.996, -1369.9255, -1239.7262, NULL, 0),
(@PATH, 4, -2025.5767, -1382.5028, -1239.7262, NULL, 0),
(@PATH, 5, -2030.5376, -1397.9652, -1239.7262, NULL, 0),
(@PATH, 6, -2030.8411, -1422.2825, -1239.7262, NULL, 0),
(@PATH, 7, -2031.3794, -1441.8501, -1239.7262, NULL, 0),
(@PATH, 8, -2043.9795, -1457.38, -1239.7262, NULL, 0),
(@PATH, 9, -2052.97, -1466.99, -1239.7262, NULL, 13795),
(@PATH, 10, -2043.0027, -1430.9763, -1239.7262, NULL, 0),
(@PATH, 11, -2028.8873, -1416.864, -1239.7262, NULL, 0),
(@PATH, 12, -2030.5697, -1398.9899, -1239.7262, NULL, 0),
(@PATH, 13, -2027.1268, -1378.452, -1239.7263, NULL, 0),
(@PATH, 14, -2033.9156, -1362.9547, -1239.7262, NULL, 0),
(@PATH, 15, -2049.4304, -1351.6335, -1239.7262, NULL, 0),
(@PATH, 16, -2068.1113, -1322.3813, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2076.5312, `position_y`=-1301.7955, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '18950');

-- Path for Skittershaw
SET @MOVERGUID := @CGUID+191;
SET @ENTRY := 223203;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Skittershaw - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2023.8403, -1380.5121, -1239.7262, NULL, 0),
(@PATH, 1, -2021.9938, -1399.0176, -1239.7262, NULL, 0),
(@PATH, 2, -2018.9207, -1421.5668, -1239.7262, NULL, 0),
(@PATH, 3, -2015.3818, -1475.2747, -1239.7262, NULL, 0),
(@PATH, 4, -2001.58, -1474.15, -1239.7262, NULL, 15552),
(@PATH, 5, -2015.7549, -1480.6863, -1239.7262, NULL, 0),
(@PATH, 6, -2036.0023, -1503.1735, -1239.7262, NULL, 0),
(@PATH, 7, -2062.232, -1508.0094, -1239.7262, NULL, 0),
(@PATH, 8, -2080.486, -1500.286, -1239.7262, NULL, 0),
(@PATH, 9, -2081.32, -1501.18, -1239.7262, NULL, 15896),
(@PATH, 10, -2072.8025, -1453.6975, -1239.7262, NULL, 0),
(@PATH, 11, -2106.6719, -1422.9031, -1239.7262, NULL, 0),
(@PATH, 12, -2107.7546, -1396.8063, -1239.7262, NULL, 0),
(@PATH, 13, -2110.4617, -1363.3315, -1239.7262, NULL, 0),
(@PATH, 14, -2087.8289, -1348.8037, -1239.7262, NULL, 0),
(@PATH, 15, -2054.8442, -1323.1217, -1239.7262, NULL, 0),
(@PATH, 16, -2043.67, -1315.31, -1239.7262, NULL, 15832),
(@PATH, 17, -2051.688, -1353.9124, -1239.7262, NULL, 0),
(@PATH, 18, -2038.2596, -1367.9349, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2023.8403, `position_y`=-1380.5121, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ascended Aristocrat
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+131;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+131, @CGUID+131, 0, 0, 515, 0, 0),
(@CGUID+131, @CGUID+132, 5, 0, 515, 9, 0),
(@CGUID+131, @CGUID+130, 5, 90, 515, 9, 0),
(@CGUID+131, @CGUID+133, 6, 50, 515, 9, 0);

SET @MOVERGUID := @CGUID+131;
SET @ENTRY := 220004;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ascended Aristocrat - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2028.6562, -1374.1632, -1239.7262, NULL, 0),
(@PATH, 1, -2036.1754, -1365.8993, -1239.7262, NULL, 0),
(@PATH, 2, -2047.7118, -1357.0851, -1239.7262, NULL, 0),
(@PATH, 3, -2069.8784, -1341.132, -1239.7262, NULL, 0),
(@PATH, 4, -2087.8455, -1343.5764, -1239.7262, NULL, 0),
(@PATH, 5, -2109.3801, -1374.6285, -1239.7262, NULL, 0),
(@PATH, 6, -2115.467, -1392.6216, -1239.7262, NULL, 0),
(@PATH, 7, -2115.3298, -1413.849, -1239.7262, NULL, 0),
(@PATH, 8, -2104.9548, -1431.5747, -1239.7262, NULL, 0),
(@PATH, 9, -2084.9426, -1450.0781, -1239.7262, NULL, 0),
(@PATH, 10, -2059.3315, -1452.2327, -1239.7262, NULL, 0),
(@PATH, 11, -2041.5104, -1440.7153, -1239.7262, NULL, 0),
(@PATH, 12, -2036.5608, -1430.0504, -1239.7262, NULL, 0),
(@PATH, 13, -2023.0868, -1415.6129, -1239.7262, NULL, 0),
(@PATH, 14, -2023.0938, -1389.6459, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2028.6562, `position_y`=-1374.1632, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '441664');

-- Path for Ascended Aristocrat
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+218;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+218, @CGUID+218, 0, 0, 515, 0, 0),
(@CGUID+218, @CGUID+223, 3, 270, 515, 8, 24),
(@CGUID+218, @CGUID+219, 3, 90, 515, 8, 24),
(@CGUID+218, @CGUID+227, 5, 20, 515, 8, 24),
(@CGUID+218, @CGUID+222, 5, 340, 515, 8, 24);

SET @MOVERGUID := @CGUID+218;
SET @ENTRY := 220004;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ascended Aristocrat - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2083.2231, -1446.2307, -1239.7262, NULL, 0),
(@PATH, 1, -2062.9685, -1449.533, -1239.7262, NULL, 0),
(@PATH, 2, -2055.626, -1441.2938, -1239.7262, NULL, 0),
(@PATH, 3, -1993.75, -1460.416, -1239.7262, NULL, 0),
(@PATH, 4, -1969.5691, -1441.3639, -1244.1853, NULL, 0),
(@PATH, 5, -1961.681, -1417.961, -1244.1853, NULL, 0),
(@PATH, 6, -1917.4623, -1444.7911, -1244.1853, NULL, 0),
(@PATH, 7, -1872.4845, -1423.2329, -1244.1853, NULL, 0),
(@PATH, 8, -1851.4496, -1404.6763, -1243.628, NULL, 17399),
(@PATH, 9, -1872.4845, -1423.2329, -1244.1853, NULL, 0),
(@PATH, 10, -1917.8346, -1452.5034, -1244.1853, NULL, 0),
(@PATH, 11, -1975.9827, -1426.0764, -1244.1853, NULL, 0),
(@PATH, 12, -1973.7515, -1439.5465, -1244.1853, NULL, 0),
(@PATH, 13, -1993.1708, -1461.3282, -1239.7262, NULL, 0),
(@PATH, 14, -2052.6409, -1461.6404, -1239.7262, NULL, 0),
(@PATH, 15, -2062.0566, -1467.5117, -1239.7262, NULL, 0),
(@PATH, 16, -2082.4326, -1461.7657, -1239.7262, NULL, 0),
(@PATH, 17, -2109.0085, -1472.7615, -1239.7262, NULL, 0),
(@PATH, 18, -2136.8474, -1487.291, -1223.2917, NULL, 0),
(@PATH, 19, -2155.3845, -1497.7493, -1223.6431, NULL, 0),
(@PATH, 20, -2181.4846, -1512.2261, -1239.0806, NULL, 0),
(@PATH, 21, -2197.3071, -1524.6871, -1239.7262, NULL, 0),
(@PATH, 22, -2195.213, -1551.1985, -1239.2815, NULL, 0),
(@PATH, 23, -2198.3855, -1569.8796, -1245.8163, NULL, 0),
(@PATH, 24, -2192.621, -1595.3162, -1246.5822, NULL, 14609),
(@PATH, 25, -2194.9802, -1568.8809, -1246.5092, NULL, 0),
(@PATH, 26, -2195.197, -1551.3718, -1239.4178, NULL, 0),
(@PATH, 27, -2196.0273, -1521.9535, -1239.7262, NULL, 0),
(@PATH, 28, -2181.1963, -1512.0437, -1238.9542, NULL, 0),
(@PATH, 29, -2155.4482, -1497.7852, -1223.6726, NULL, 0),
(@PATH, 30, -2136.859, -1487.2974, -1223.2866, NULL, 0),
(@PATH, 31, -2108.799, -1472.649, -1239.7262, NULL, 0),
(@PATH, 32, -2083.2231, -1446.2307, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2083.2231, `position_y`=-1446.2307, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature` SET `position_x`=-2083.2231, `position_y`=-1446.2307, `position_z`=-1239.7262 WHERE `guid` IN (@CGUID+223, @CGUID+219, @CGUID+227, @CGUID+222);
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ascended Aristocrat
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+141;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+141, @CGUID+141, 0, 0, 515, 0, 0),
(@CGUID+141, @CGUID+146, 3, 270, 515, 0, 0),
(@CGUID+141, @CGUID+140, 3, 90, 515, 0, 0),
(@CGUID+141, @CGUID+143, 5, 20, 515, 0, 0),
(@CGUID+141, @CGUID+145, 5, 340, 515, 0, 0);

SET @MOVERGUID := @CGUID+141;
SET @ENTRY := 220004;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ascended Aristocrat - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2096.3242, -1352.2927, -1239.7262, NULL, 0),
(@PATH, 1, -2098.269, -1355.0973, -1239.7262, NULL, 0),
(@PATH, 2, -2100.211, -1357.8973, -1239.7262, NULL, 0),
(@PATH, 3, -2102.1448, -1360.6857, -1239.7262, NULL, 0),
(@PATH, 4, -2104.0896, -1363.4904, -1239.7262, NULL, 0),
(@PATH, 5, -2106.033, -1366.2926, -1239.7262, NULL, 0),
(@PATH, 6, -2107.9844, -1369.1063, -1239.7262, NULL, 0),
(@PATH, 7, -2110.4243, -1371.4735, -1239.7262, NULL, 0),
(@PATH, 8, -2111.418, -1374.4114, -1239.7262, NULL, 0),
(@PATH, 9, -2112.3982, -1377.3085, -1239.7262, NULL, 0),
(@PATH, 10, -2113.3855, -1380.227, -1239.7262, NULL, 0),
(@PATH, 11, -2114.372, -1383.1433, -1239.7262, NULL, 0),
(@PATH, 12, -2115.3643, -1386.0764, -1239.7262, NULL, 0),
(@PATH, 13, -2117.4893, -1389.193, -1239.7262, NULL, 0),
(@PATH, 14, -2117.4695, -1392.2749, -1239.7262, NULL, 0),
(@PATH, 15, -2117.4497, -1395.329, -1239.7262, NULL, 0),
(@PATH, 16, -2117.43, -1398.3907, -1239.7262, NULL, 0),
(@PATH, 17, -2117.4102, -1401.4524, -1239.7262, NULL, 0),
(@PATH, 18, -2117.3904, -1404.5142, -1239.7262, NULL, 0),
(@PATH, 19, -2117.3706, -1407.5557, -1239.7262, NULL, 0),
(@PATH, 20, -2118.917, -1411.6794, -1239.7262, NULL, 0),
(@PATH, 21, -2117.3506, -1414.3558, -1239.7262, NULL, 0),
(@PATH, 22, -2115.7944, -1417.0145, -1239.7262, NULL, 0),
(@PATH, 23, -2114.2292, -1419.6887, -1239.7262, NULL, 0),
(@PATH, 24, -2112.6716, -1422.3496, -1239.7262, NULL, 0),
(@PATH, 25, -2111.1104, -1425.0172, -1239.7262, NULL, 0),
(@PATH, 26, -2109.5618, -1427.6628, -1239.7262, NULL, 0),
(@PATH, 27, -2108.8457, -1430.7009, -1239.7262, NULL, 0),
(@PATH, 28, -2106.5452, -1432.8281, -1239.7262, NULL, 0),
(@PATH, 29, -2104.267, -1434.9343, -1239.7262, NULL, 0),
(@PATH, 30, -2101.974, -1437.0546, -1239.7262, NULL, 0),
(@PATH, 31, -2099.679, -1439.1765, -1239.7262, NULL, 0),
(@PATH, 32, -2097.4087, -1441.2759, -1239.7262, NULL, 0),
(@PATH, 33, -2095.1135, -1443.3978, -1239.7262, NULL, 0),
(@PATH, 34, -2092.8262, -1445.5128, -1239.7262, NULL, 0),
(@PATH, 35, -2090.535, -1447.6312, -1239.7262, NULL, 0),
(@PATH, 36, -2088.9067, -1451.7517, -1239.7262, NULL, 0),
(@PATH, 37, -2085.7532, -1452.017, -1239.7262, NULL, 0),
(@PATH, 38, -2082.6123, -1452.2811, -1239.7262, NULL, 0),
(@PATH, 39, -2079.456, -1452.5466, -1239.7262, NULL, 0),
(@PATH, 40, -2076.2974, -1452.8124, -1239.7262, NULL, 0),
(@PATH, 41, -2073.1384, -1453.0781, -1239.7262, NULL, 0),
(@PATH, 42, -2069.9822, -1453.3438, -1239.7262, NULL, 0),
(@PATH, 43, -2066.831, -1453.6088, -1239.7262, NULL, 0),
(@PATH, 44, -2064.1843, -1453.8315, -1239.7262, NULL, 0),
(@PATH, 45, -2059.668, -1454.8314, -1239.7262, NULL, 0),
(@PATH, 46, -2057.0732, -1453.1544, -1239.7262, NULL, 0),
(@PATH, 47, -2054.4805, -1451.4788, -1239.7262, NULL, 0),
(@PATH, 48, -2051.89, -1449.8046, -1239.7262, NULL, 0),
(@PATH, 49, -2049.2993, -1448.1302, -1239.7262, NULL, 0),
(@PATH, 50, -2046.7063, -1446.4547, -1239.7262, NULL, 0),
(@PATH, 51, -2044.2261, -1444.8517, -1239.7262, NULL, 0),
(@PATH, 52, -2040.3259, -1442.9142, -1239.7262, NULL, 0),
(@PATH, 53, -2039.0416, -1440.1467, -1239.7262, NULL, 0),
(@PATH, 54, -2037.752, -1437.3679, -1239.7262, NULL, 0),
(@PATH, 55, -2036.5231, -1434.72, -1239.7262, NULL, 0),
(@PATH, 56, -2035.8972, -1432.2708, -1239.7262, NULL, 0),
(@PATH, 57, -2033.8207, -1430.0458, -1239.7262, NULL, 0),
(@PATH, 58, -2031.751, -1427.8281, -1239.7262, NULL, 0),
(@PATH, 59, -2029.6556, -1425.5829, -1239.7262, NULL, 0),
(@PATH, 60, -2027.5706, -1423.3486, -1239.7262, NULL, 0),
(@PATH, 61, -2025.4991, -1421.1292, -1239.7262, NULL, 0),
(@PATH, 62, -2021.0857, -1419.5006, -1239.7262, NULL, 0),
(@PATH, 63, -2021.0865, -1416.3337, -1239.7263, NULL, 0),
(@PATH, 64, -2021.0874, -1413.1615, -1239.7262, NULL, 0),
(@PATH, 65, -2021.0883, -1409.984, -1239.7262, NULL, 0),
(@PATH, 66, -2021.0891, -1406.8145, -1239.7262, NULL, 0),
(@PATH, 67, -2021.09, -1403.637, -1239.7262, NULL, 0),
(@PATH, 68, -2021.0908, -1400.4437, -1239.7262, NULL, 0),
(@PATH, 69, -2021.0917, -1397.2584, -1239.7262, NULL, 0),
(@PATH, 70, -2021.0925, -1394.0967, -1239.7262, NULL, 0),
(@PATH, 71, -2020.5426, -1390.8317, -1239.7262, NULL, 0),
(@PATH, 72, -2021.6047, -1387.8754, -1239.7263, NULL, 0),
(@PATH, 73, -2022.6677, -1384.9165, -1239.7262, NULL, 0),
(@PATH, 74, -2023.7264, -1381.9698, -1239.7262, NULL, 0),
(@PATH, 75, -2024.793, -1379.0013, -1239.7262, NULL, 0),
(@PATH, 76, -2025.1992, -1374.9908, -1239.7262, NULL, 0),
(@PATH, 77, -2027.2482, -1372.739, -1239.7262, NULL, 0),
(@PATH, 78, -2029.2937, -1370.4908, -1239.7262, NULL, 0),
(@PATH, 79, -2031.3392, -1368.2428, -1239.7262, NULL, 0),
(@PATH, 80, -2033.343, -1365.5464, -1239.7262, NULL, 0),
(@PATH, 81, -2035.7711, -1363.6913, -1239.7262, NULL, 0),
(@PATH, 82, -2038.1893, -1361.8436, -1239.7262, NULL, 0),
(@PATH, 83, -2040.6134, -1359.9916, -1239.7262, NULL, 0),
(@PATH, 84, -2043.0195, -1358.1532, -1239.7262, NULL, 0),
(@PATH, 85, -2043.9462, -1357.331, -1239.7262, NULL, 0),
(@PATH, 86, -2046.6029, -1355.4191, -1239.7262, NULL, 0),
(@PATH, 87, -2049.2422, -1353.5197, -1239.7262, NULL, 0),
(@PATH, 88, -2051.8792, -1351.6217, -1239.7262, NULL, 0),
(@PATH, 89, -2054.536, -1349.7098, -1239.7262, NULL, 0),
(@PATH, 90, -2057.1948, -1347.7963, -1239.7262, NULL, 0),
(@PATH, 91, -2059.8472, -1345.8873, -1239.7262, NULL, 0),
(@PATH, 92, -2062.4841, -1343.9895, -1239.7262, NULL, 0),
(@PATH, 93, -2065.1387, -1342.0791, -1239.7262, NULL, 0),
(@PATH, 94, -2067.7551, -1338.8247, -1239.7262, NULL, 0),
(@PATH, 95, -2070.9387, -1339.2578, -1239.7262, NULL, 0),
(@PATH, 96, -2074.1538, -1339.6952, -1239.7262, NULL, 0),
(@PATH, 97, -2077.3374, -1340.1283, -1239.7262, NULL, 0),
(@PATH, 98, -2080.5396, -1340.564, -1239.7262, NULL, 0),
(@PATH, 99, -2083.7441, -1341, -1239.7262, NULL, 0),
(@PATH, 100, -2083.8623, -1341.0161, -1239.7262, NULL, 0),
(@PATH, 101, -2088.5261, -1341.0483, -1239.7262, NULL, 0),
(@PATH, 102, -2090.442, -1343.8108, -1239.7262, NULL, 0),
(@PATH, 103, -2092.3545, -1346.5686, -1239.7262, NULL, 0),
(@PATH, 104, -2094.256, -1349.3107, -1239.7262, NULL, 0),
(@PATH, 105, -2096.1719, -1352.0731, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2096.3242, `position_y`=-1352.2927, `position_z`=-1239.7262 WHERE `guid` IN (@CGUID+146, @CGUID+140, @CGUID+143, @CGUID+145);
UPDATE `creature` SET `position_x`=-2096.3242, `position_y`=-1352.2927, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ascended Aristocrat
SET @MOVERGUID := @CGUID+217;
SET @ENTRY := 220004;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ascended Aristocrat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2119.325, -1428.9137, -1239.7262, NULL, 0),
(@PATH, 1, -2111.2773, -1448.6975, -1239.7262, NULL, 0),
(@PATH, 2, -2128.5261, -1457.1393, -1239.7262, NULL, 0),
(@PATH, 3, -2127.28, -1462.55, -1239.7262, NULL, 11655),
(@PATH, 4, -2110.9854, -1448.2532, -1239.7262, NULL, 0),
(@PATH, 5, -2119.3694, -1428.083, -1239.7262, NULL, 0),
(@PATH, 6, -2122.1428, -1398.2875, -1239.7262, NULL, 0),
(@PATH, 7, -2113.5808, -1363.0642, -1239.7262, NULL, 0),
(@PATH, 8, -2109.2827, -1332.5804, -1239.7262, NULL, 0),
(@PATH, 9, -2110.416, -1332.291, -1239.7262, NULL, 0),
(@PATH, 10, -2112.5918, -1330.668, -1239.1654, NULL, 0),
(@PATH, 11, -2113.691, -1330.0981, -1238.8722, NULL, 0),
(@PATH, 12, -2116.8696, -1328.45, -1236.9382, NULL, 0),
(@PATH, 13, -2124.6816, -1324.3995, -1232.4113, NULL, 0),
(@PATH, 14, -2126.5857, -1323.4122, -1231.3358, NULL, 0),
(@PATH, 15, -2127.751, -1322.8081, -1230.5935, NULL, 0),
(@PATH, 16, -2128.8362, -1322.2455, -1229.9962, NULL, 0),
(@PATH, 17, -2129.448, -1321.9282, -1229.5536, NULL, 0),
(@PATH, 18, -2130.297, -1321.488, -1229.1239, NULL, 0),
(@PATH, 19, -2133.334, -1319.9135, -1227.3376, NULL, 0),
(@PATH, 20, -2134.191, -1319.4691, -1226.8832, NULL, 0),
(@PATH, 21, -2138.0596, -1317.4633, -1224.5734, NULL, 0),
(@PATH, 22, -2140.8848, -1315.9985, -1223.1691, NULL, 0),
(@PATH, 23, -2142.3545, -1315.2043, -1222.8823, NULL, 0),
(@PATH, 24, -2144.9692, -1313.6923, -1222.9156, NULL, 0),
(@PATH, 25, -2145.9194, -1313.1427, -1222.5001, NULL, 0),
(@PATH, 26, -2146.609, -1312.744, -1222.8354, NULL, 0),
(@PATH, 27, -2151.0676, -1310.1655, -1222.8184, NULL, 0),
(@PATH, 28, -2154.496, -1308.1827, -1222.8485, NULL, 0),
(@PATH, 29, -2156.5044, -1307.0214, -1222.9126, NULL, 0),
(@PATH, 30, -2157.5024, -1306.4442, -1223.1381, NULL, 0),
(@PATH, 31, -2194.6775, -1283.536, -1239.7262, NULL, 0),
(@PATH, 32, -2212.556, -1285.7418, -1239.7262, NULL, 0),
(@PATH, 33, -2225.9492, -1270.5635, -1239.7262, NULL, 0),
(@PATH, 34, -2234.04, -1274.4, -1239.7262, NULL, 12024),
(@PATH, 35, -2218.0476, -1286.7206, -1239.7262, NULL, 0),
(@PATH, 36, -2193.8652, -1286.3479, -1239.7262, NULL, 0),
(@PATH, 37, -2157.4968, -1306.4475, -1223.1368, NULL, 0),
(@PATH, 38, -2141.8167, -1315.5154, -1222.9885, NULL, 0),
(@PATH, 39, -2108.0703, -1335.0734, -1239.7262, NULL, 0),
(@PATH, 40, -2113.5657, -1362.9293, -1239.7262, NULL, 0),
(@PATH, 41, -2122.1558, -1396.7574, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2119.325, `position_y`=-1428.9137, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ascended Aristocrat
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+36;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+36, @CGUID+36, 0, 0, 515, 0, 0),
(@CGUID+36, @CGUID+48, 4, 0, 515, 0, 0),
(@CGUID+36, @CGUID+82, 4, 270, 515, 0, 0),
(@CGUID+36, @CGUID+41, 5, 310, 515, 0, 0);

SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 220004;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ascended Aristocrat - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2083.31, -1169.9, -1244.2147, NULL, 12546),
(@PATH, 1, -2100.308, -1185.5289, -1244.2147, NULL, 0),
(@PATH, 2, -2119.861, -1181.404, -1244.2065, NULL, 0),
(@PATH, 3, -2130.8162, -1191.2782, -1244.0782, NULL, 0),
(@PATH, 4, -2159.0417, -1211.4001, -1244.181, NULL, 0),
(@PATH, 5, -2166.2, -1235.5239, -1239.6313, NULL, 0),
(@PATH, 6, -2189.245, -1260.0441, -1239.7262, NULL, 0),
(@PATH, 7, -2204.1707, -1271.637, -1239.7262, NULL, 0),
(@PATH, 8, -2204.1707, -1271.637, -1239.7262, NULL, 15308),
(@PATH, 9, -2193.8652, -1286.3479, -1239.7262, NULL, 0),
(@PATH, 10, -2157.4968, -1306.4475, -1223.1368, NULL, 0),
(@PATH, 11, -2141.8167, -1315.5154, -1222.9885, NULL, 0),
(@PATH, 12, -2108.0703, -1335.0734, -1239.7262, NULL, 0),
(@PATH, 13, -2095.855, -1350.5533, -1239.7262, NULL, 0),
(@PATH, 14, -2051.8425, -1355.9586, -1239.7262, NULL, 0),
(@PATH, 15, -2039.4628, -1369.3143, -1239.7262, NULL, 0),
(@PATH, 16, -2024.1327, -1380.8473, -1239.7262, NULL, 0),
(@PATH, 17, -2020.177, -1399.2413, -1239.7262, NULL, 0),
(@PATH, 18, -2017.0935, -1421.4572, -1239.7262, NULL, 0),
(@PATH, 19, -2013.7021, -1478.2957, -1239.7262, NULL, 0),
(@PATH, 20, -1988.2914, -1490.0626, -1239.8254, NULL, 0),
(@PATH, 21, -1984.72, -1484.63, -1239.7473, NULL, 12338),
(@PATH, 22, -1994.5382, -1460.8242, -1239.7262, NULL, 0),
(@PATH, 23, -1972.9727, -1437.7543, -1244.1853, NULL, 0),
(@PATH, 24, -1980.642, -1417.8654, -1244.1853, NULL, 0),
(@PATH, 25, -1978.6647, -1393.1594, -1244.1853, NULL, 0),
(@PATH, 26, -1973.9565, -1364.5192, -1244.1853, NULL, 0),
(@PATH, 27, -1987.3789, -1348.4386, -1244.1853, NULL, 0),
(@PATH, 28, -1981.0585, -1315.7753, -1244.1853, NULL, 0),
(@PATH, 29, -1996.1517, -1294.4852, -1239.5823, NULL, 0),
(@PATH, 30, -2014.0851, -1270.5587, -1239.7262, NULL, 0),
(@PATH, 31, -2026.2423, -1265.3777, -1239.1149, NULL, 0),
(@PATH, 32, -2058.5854, -1241.4816, -1244.1636, NULL, 0),
(@PATH, 33, -2046.9701, -1211.3104, -1244.1873, NULL, 0),
(@PATH, 34, -2070.726, -1183.613, -1244.2147, NULL, 0),
(@PATH, 35, -2080.8643, -1176.1981, -1244.2147, NULL, 0);

UPDATE `creature` SET `position_x`=-2083.31, `position_y`=-1169.9, `position_z`=-1244.2147 WHERE `guid` IN (@CGUID+48, @CGUID+82, @CGUID+41);
UPDATE `creature` SET `position_x`=-2083.31, `position_y`=-1169.9, `position_z`=-1244.2147, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ascended Aristocrat
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+135;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+135, @CGUID+135, 0, 0, 515, 0, 0),
(@CGUID+135, @CGUID+129, 4, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+135;
SET @ENTRY := 220004;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Ascended Aristocrat - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2119.659, -1180.5337, -1244.2078, NULL, 0),
(@PATH, 1, -2101.9563, -1170.6698, -1243.6152, NULL, 0),
(@PATH, 2, -2113.37, -1149.39, -1244.2147, NULL, 11902),
(@PATH, 3, -2108.1575, -1179.6553, -1244.2147, NULL, 0),
(@PATH, 4, -2120.0037, -1180.4536, -1244.2069, NULL, 0),
(@PATH, 5, -2144.5374, -1159.2565, -1244.1833, NULL, 0),
(@PATH, 6, -2143.372, -1131.3297, -1244.1855, NULL, 0),
(@PATH, 7, -2144.79, -1114.7, -1243.8184, NULL, 12199),
(@PATH, 8, -2143.372, -1131.3297, -1244.1855, NULL, 0),
(@PATH, 9, -2142.68, -1163.3787, -1244.1722, NULL, 0),
(@PATH, 10, -2129.8, -1169.15, -1244.1868, NULL, 17265);

UPDATE `creature` SET `position_x`=-2119.659, `position_y`=-1180.5337, `position_z`=-1244.2078 WHERE `guid`= @CGUID+129;
UPDATE `creature` SET `position_x`=-2119.659, `position_y`=-1180.5337, `position_z`=-1244.2078, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Royal Attendant
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+56;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+56, @CGUID+56, 0, 0, 515, 0, 0),
(@CGUID+56, @CGUID+37, 5, 0, 515, 9, 0),
(@CGUID+56, @CGUID+51, 5, 90, 515, 9, 0),
(@CGUID+56, @CGUID+42, 6, 50, 515, 9, 0);

SET @MOVERGUID := @CGUID+56;
SET @ENTRY := 222538;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Loyal Attendant - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2040.0887, -1309.9312, -1239.7262, NULL, 0),
(@PATH, 1, -2043.076, -1310.3993, -1239.7262, NULL, 0),
(@PATH, 2, -2046.0833, -1310.8706, -1239.7262, NULL, 0),
(@PATH, 3, -2049.078, -1311.3398, -1239.7262, NULL, 0),
(@PATH, 4, -2052.0752, -1311.8096, -1239.7262, NULL, 0),
(@PATH, 5, -2055.0725, -1312.2793, -1239.7262, NULL, 0),
(@PATH, 6, -2058.055, -1312.7467, -1239.7263, NULL, 0),
(@PATH, 7, -2061.047, -1313.2156, -1239.7262, NULL, 0),
(@PATH, 8, -2064.0444, -1313.6853, -1239.7262, NULL, 0),
(@PATH, 9, -2067.05, -1313.7003, -1239.7262, NULL, 0),
(@PATH, 10, -2070.0508, -1313.6107, -1239.7262, NULL, 0),
(@PATH, 11, -2073.0413, -1313.5212, -1239.7262, NULL, 0),
(@PATH, 12, -2076.0417, -1313.4316, -1239.7262, NULL, 0),
(@PATH, 13, -2079.0251, -1313.3424, -1239.7262, NULL, 0),
(@PATH, 14, -2082.0007, -1313.2535, -1239.7262, NULL, 0),
(@PATH, 15, -2085.0088, -1313.1636, -1239.7262, NULL, 0),
(@PATH, 16, -2088.0044, -1313.0741, -1239.7262, NULL, 0),
(@PATH, 17, -2091.0073, -1312.9843, -1239.7262, NULL, 0),
(@PATH, 18, -2094.0127, -1312.8944, -1239.7262, NULL, 0),
(@PATH, 19, -2097.0183, -1312.8046, -1239.7262, NULL, 0),
(@PATH, 20, -2100.0288, -1312.7146, -1239.7262, NULL, 0),
(@PATH, 21, -2103.0193, -1312.6252, -1239.7262, NULL, 0),
(@PATH, 22, -2105.7715, -1311.3928, -1239.7262, NULL, 0),
(@PATH, 23, -2108.487, -1310.043, -1239.7262, NULL, 0),
(@PATH, 24, -2111.1846, -1308.7021, -1239.7262, NULL, 0),
(@PATH, 25, -2113.8867, -1307.3591, -1239.7262, NULL, 0),
(@PATH, 26, -2116.582, -1306.0193, -1239.7262, NULL, 0),
(@PATH, 27, -2119.2998, -1304.6685, -1239.7262, NULL, 0),
(@PATH, 28, -2122.0063, -1303.3231, -1239.7262, NULL, 0),
(@PATH, 29, -2124.731, -1301.9689, -1239.7262, NULL, 0),
(@PATH, 30, -2127.4375, -1300.6237, -1239.7262, NULL, 0),
(@PATH, 31, -2130.173, -1299.2638, -1239.7262, NULL, 0),
(@PATH, 32, -2132.8687, -1297.9241, -1239.7262, NULL, 0),
(@PATH, 33, -2135.5818, -1296.5754, -1239.7262, NULL, 0),
(@PATH, 34, -2138.2861, -1295.2312, -1239.7262, NULL, 0),
(@PATH, 35, -2141.0017, -1293.8815, -1239.7262, NULL, 0),
(@PATH, 36, -2143.7217, -1292.5295, -1239.7262, NULL, 0),
(@PATH, 37, -2146.4329, -1291.182, -1239.7262, NULL, 0),
(@PATH, 38, -2149.1528, -1289.83, -1239.7262, NULL, 0),
(@PATH, 39, -2151.8525, -1288.488, -1239.7262, NULL, 0),
(@PATH, 40, -2154.5815, -1287.1316, -1239.7262, NULL, 0),
(@PATH, 41, -2157.2905, -1285.7852, -1239.7262, NULL, 0),
(@PATH, 42, -2160.017, -1284.4298, -1239.7262, NULL, 0),
(@PATH, 43, -2162.7395, -1283.0767, -1239.7262, NULL, 0),
(@PATH, 44, -2165.4573, -1281.7258, -1239.7262, NULL, 0),
(@PATH, 45, -2168.1838, -1280.3705, -1239.7262, NULL, 0),
(@PATH, 46, -2170.895, -1279.023, -1239.7262, NULL, 0),
(@PATH, 47, -2173.6106, -1277.6732, -1239.7262, NULL, 0),
(@PATH, 48, -2176.3215, -1276.3257, -1239.7262, NULL, 0),
(@PATH, 49, -2179.044, -1274.9725, -1239.7262, NULL, 0),
(@PATH, 50, -2181.7483, -1273.6283, -1239.7262, NULL, 0),
(@PATH, 51, -2184.4749, -1272.273, -1239.7262, NULL, 0),
(@PATH, 52, -2187.4216, -1271.1633, -1239.7262, NULL, 0),
(@PATH, 53, -2190.7153, -1270.3829, -1239.7262, NULL, 0),
(@PATH, 54, -2194.0334, -1269.5967, -1239.7262, NULL, 0),
(@PATH, 55, -2197.3438, -1268.8124, -1239.7262, NULL, 0),
(@PATH, 56, -2200.692, -1268.019, -1239.7262, NULL, 0),
(@PATH, 57, -2203.9993, -1267.2355, -1239.7262, NULL, 0),
(@PATH, 58, -2207.3394, -1266.444, -1239.7262, NULL, 0),
(@PATH, 59, -2210.6277, -1265.6649, -1239.7262, NULL, 0),
(@PATH, 60, -2213.9377, -1264.8806, -1239.7262, NULL, 0),
(@PATH, 61, -2217.2505, -1264.0957, -1239.7262, NULL, 0),
(@PATH, 62, -2220.5715, -1263.3088, -1239.7262, NULL, 0),
(@PATH, 63, -2223.8733, -1262.5265, -1239.7262, NULL, 0),
(@PATH, 64, -2227.1917, -1261.7402, -1239.7262, NULL, 0),
(@PATH, 65, -2230.5264, -1260.9502, -1239.7262, NULL, 0),
(@PATH, 66, -2232.8728, -1260.4559, -1239.7262, NULL, 0),
(@PATH, 67, -2233.158, -1260.5801, -1239.7262, NULL, 0),
(@PATH, 68, -2233.6138, -1260.6244, -1239.1323, NULL, 1006),
(@PATH, 69, -2234.502, -1263.4983, -1238.9485, NULL, 9689),
(@PATH, 70, -2235.1877, -1262.3484, -1238.8184, NULL, 0),
(@PATH, 71, -2235.3462, -1262.0105, -1238.8184, NULL, 1130),
(@PATH, 72, -2232.764, -1257.4019, -1239.7262, NULL, 0),
(@PATH, 73, -2229.2551, -1257.0808, -1239.7262, NULL, 0),
(@PATH, 74, -2225.729, -1256.7582, -1239.7262, NULL, 0),
(@PATH, 75, -2222.1914, -1256.4344, -1239.7262, NULL, 0),
(@PATH, 76, -2218.6855, -1256.1135, -1239.7262, NULL, 0),
(@PATH, 77, -2215.1682, -1255.7917, -1239.7262, NULL, 0),
(@PATH, 78, -2211.6711, -1255.4717, -1239.7262, NULL, 0),
(@PATH, 79, -2208.145, -1255.149, -1239.7262, NULL, 0),
(@PATH, 80, -2204.616, -1254.826, -1239.7262, NULL, 0),
(@PATH, 81, -2201.0898, -1254.5034, -1239.7262, NULL, 0),
(@PATH, 82, -2197.564, -1254.1807, -1239.7262, NULL, 0),
(@PATH, 83, -2194.0493, -1253.8591, -1239.7262, NULL, 0),
(@PATH, 84, -2190.5378, -1253.5377, -1239.7262, NULL, 0),
(@PATH, 85, -2187.0408, -1253.2178, -1239.7263, NULL, 0),
(@PATH, 86, -2183.5378, -1252.8972, -1239.7262, NULL, 0),
(@PATH, 87, -2182.599, -1253.0363, -1239.7262, NULL, 0),
(@PATH, 88, -2181.1072, -1251.8752, -1239.7262, NULL, 0),
(@PATH, 89, -2179.1733, -1249.9307, -1239.7262, NULL, 0),
(@PATH, 90, -2176.9478, -1247.7048, -1239.7262, NULL, 0),
(@PATH, 91, -2175.7559, -1246.244, -1238.8765, NULL, 0),
(@PATH, 92, -2174.221, -1243.6677, -1238.2246, NULL, 0),
(@PATH, 93, -2172.5537, -1241.0295, -1238.223, NULL, 0),
(@PATH, 94, -2170.9763, -1238.2439, -1238.437, NULL, 0),
(@PATH, 95, -2169.369, -1235.5531, -1239.1547, NULL, 0),
(@PATH, 96, -2167.6357, -1232.6251, -1240.6115, NULL, 0),
(@PATH, 97, -2165.7402, -1230.5181, -1242.1483, NULL, 0),
(@PATH, 98, -2163.9038, -1228.4761, -1243.6099, NULL, 0),
(@PATH, 99, -2163.267, -1229.7894, -1242.9176, NULL, 0),
(@PATH, 100, -2161.6704, -1224.5042, -1244.2085, NULL, 0),
(@PATH, 101, -2159.1133, -1222.8486, -1244.1971, NULL, 0),
(@PATH, 102, -2156.5793, -1221.2081, -1244.1797, NULL, 0),
(@PATH, 103, -2154.0266, -1219.5553, -1244.1569, NULL, 0),
(@PATH, 104, -2151.4443, -1217.8834, -1244.1274, NULL, 0),
(@PATH, 105, -2149.5117, -1216.6323, -1244.1079, NULL, 0),
(@PATH, 106, -2149.7603, -1215.646, -1244.1053, NULL, 0),
(@PATH, 107, -2148.624, -1212.5099, -1244.1024, NULL, 0),
(@PATH, 108, -2147.48, -1209.353, -1244.1194, NULL, 0),
(@PATH, 109, -2146.3418, -1206.2117, -1244.1458, NULL, 0),
(@PATH, 110, -2145.2053, -1203.0754, -1244.1594, NULL, 0),
(@PATH, 111, -2144.0547, -1199.9004, -1244.1471, NULL, 0),
(@PATH, 112, -2142.9182, -1196.7642, -1244.0991, NULL, 0),
(@PATH, 113, -2141.7744, -1193.6073, -1244.0369, NULL, 0),
(@PATH, 114, -2140.6426, -1190.4841, -1243.9982, NULL, 0),
(@PATH, 115, -2139.4978, -1187.3246, -1244.0426, NULL, 0),
(@PATH, 116, -2138.651, -1184.9872, -1244.0778, NULL, 0),
(@PATH, 117, -2134.6948, -1182.142, -1244.1238, NULL, 0),
(@PATH, 118, -2131.586, -1181.1165, -1244.1486, NULL, 0),
(@PATH, 119, -2128.459, -1180.085, -1244.1716, NULL, 0),
(@PATH, 120, -2125.35, -1179.0596, -1244.1884, NULL, 0),
(@PATH, 121, -2122.218, -1178.0264, -1244.201, NULL, 0),
(@PATH, 122, -2117.7917, -1177.9445, -1244.2114, NULL, 0),
(@PATH, 123, -2117.0012, -1178.0408, -1244.2125, NULL, 0),
(@PATH, 124, -2114.1963, -1176.6428, -1244.2146, NULL, 0),
(@PATH, 125, -2111.3865, -1175.2427, -1244.2147, NULL, 0),
(@PATH, 126, -2104.4749, -1175.1504, -1244.2147, NULL, 0),
(@PATH, 127, -2102.0022, -1173.7235, -1244.2147, NULL, 0),
(@PATH, 128, -2101.7468, -1171.6692, -1243.6152, NULL, 0),
(@PATH, 129, -2104.6882, -1172.2599, -1243.6726, NULL, 0),
(@PATH, 130, -2104.4636, -1167.9814, -1243.6152, NULL, 0),
(@PATH, 131, -2103.8345, -1164.9384, -1243.6154, NULL, 0),
(@PATH, 132, -2103.76, -1162.8538, -1243.6152, NULL, 0),
(@PATH, 133, -2104.1328, -1159.7714, -1243.6152, NULL, 0),
(@PATH, 134, -2103.019, -1155.1782, -1244.2147, NULL, 0),
(@PATH, 135, -2102.356, -1153.9683, -1244.2139, NULL, 0),
(@PATH, 136, -2099.749, -1155.3164, -1244.0225, NULL, 23817),
(@PATH, 137, -2099.177, -1153.1146, -1244.0262, NULL, 0),
(@PATH, 138, -2099.9333, -1156.1042, -1244.0177, NULL, 0),
(@PATH, 139, -2101.0718, -1158.7732, -1243.6754, NULL, 0),
(@PATH, 140, -2100.525, -1161.7682, -1243.6152, NULL, 0),
(@PATH, 141, -2099.5876, -1164.7186, -1243.6154, NULL, 0),
(@PATH, 142, -2099.1016, -1167.2999, -1243.6152, NULL, 0),
(@PATH, 143, -2098.1294, -1170.3015, -1243.6152, NULL, 0),
(@PATH, 144, -2096.768, -1172.1881, -1244.2147, NULL, 0),
(@PATH, 145, -2095.091, -1174.4156, -1244.2147, NULL, 0),
(@PATH, 146, -2093.6082, -1176.7039, -1244.2147, NULL, 0),
(@PATH, 147, -2094.5564, -1179.6805, -1244.2147, NULL, 0),
(@PATH, 148, -2095.4788, -1182.5751, -1244.2147, NULL, 0),
(@PATH, 149, -2096.4033, -1185.4768, -1244.2147, NULL, 0),
(@PATH, 150, -2097.3232, -1188.3643, -1244.2147, NULL, 0),
(@PATH, 151, -2098.2407, -1191.2445, -1244.2147, NULL, 0),
(@PATH, 152, -2099.161, -1194.132, -1244.2147, NULL, 0),
(@PATH, 153, -2100.0803, -1197.0178, -1244.2148, NULL, 0),
(@PATH, 154, -2100.9995, -1199.9365, -1244.2147, NULL, 0),
(@PATH, 155, -2101.3376, -1202.9541, -1244.2147, NULL, 0),
(@PATH, 156, -2101.675, -1205.9669, -1244.2147, NULL, 0),
(@PATH, 157, -2101.6755, -1208.941, -1244.2147, NULL, 0),
(@PATH, 158, -2101.1892, -1211.8607, -1244.2147, NULL, 0),
(@PATH, 159, -2100.7007, -1214.795, -1244.2147, NULL, 0),
(@PATH, 160, -2100.2107, -1217.7365, -1244.2147, NULL, 0),
(@PATH, 161, -2099.5386, -1220.595, -1244.2148, NULL, 0),
(@PATH, 162, -2097.2903, -1222.6042, -1244.2147, NULL, 0),
(@PATH, 163, -2095.024, -1224.6296, -1244.2147, NULL, 0),
(@PATH, 164, -2092.7744, -1226.64, -1244.2147, NULL, 0),
(@PATH, 165, -2090.5117, -1228.662, -1244.2147, NULL, 0),
(@PATH, 166, -2088.2493, -1230.684, -1244.2117, NULL, 0),
(@PATH, 167, -2085.9773, -1232.7144, -1244.2081, NULL, 0),
(@PATH, 168, -2083.7202, -1234.7313, -1244.2015, NULL, 0),
(@PATH, 169, -2081.4595, -1236.7517, -1244.1898, NULL, 0),
(@PATH, 170, -2079.193, -1238.7771, -1244.1841, NULL, 0),
(@PATH, 171, -2076.7214, -1240.3042, -1244.1819, NULL, 0),
(@PATH, 172, -2073.702, -1240.6549, -1244.1841, NULL, 0),
(@PATH, 173, -2070.64, -1241.0105, -1244.1783, NULL, 0),
(@PATH, 174, -2067.593, -1241.3644, -1244.1699, NULL, 0),
(@PATH, 175, -2064.5337, -1241.7197, -1244.1635, NULL, 0),
(@PATH, 176, -2061.4844, -1242.0739, -1244.162, NULL, 0),
(@PATH, 177, -2058.4224, -1242.4294, -1244.1647, NULL, 0),
(@PATH, 178, -2055.378, -1242.7831, -1244.1708, NULL, 0),
(@PATH, 179, -2053.1262, -1244.46, -1244.1759, NULL, 0),
(@PATH, 180, -2051.1245, -1246.6729, -1244.1799, NULL, 0),
(@PATH, 181, -2048.862, -1248.8268, -1244.1832, NULL, 0),
(@PATH, 182, -2046.4026, -1250.7393, -1244.185, NULL, 0),
(@PATH, 183, -2044.1837, -1252.3066, -1242.9047, NULL, 0),
(@PATH, 184, -2042.0532, -1254.2435, -1241.5499, NULL, 0),
(@PATH, 185, -2039.9794, -1256.1285, -1240.0914, NULL, 0),
(@PATH, 186, -2037.7887, -1258.1196, -1239.1318, NULL, 0),
(@PATH, 187, -2035.4738, -1260.2238, -1239.0215, NULL, 0),
(@PATH, 188, -2033.1447, -1262.3407, -1238.962, NULL, 0),
(@PATH, 189, -2030.828, -1264.4464, -1238.8724, NULL, 0),
(@PATH, 190, -2028.7593, -1266.3268, -1239.0238, NULL, 0),
(@PATH, 191, -2027.2828, -1266.9194, -1239.7262, NULL, 0),
(@PATH, 192, -2026.7133, -1269.2317, -1239.7262, NULL, 0),
(@PATH, 193, -2026.1823, -1272.191, -1239.7262, NULL, 0),
(@PATH, 194, -2025.6473, -1275.1722, -1239.7262, NULL, 0),
(@PATH, 195, -2025.1155, -1278.1365, -1239.7262, NULL, 0),
(@PATH, 196, -2025.0992, -1281.1113, -1239.7262, NULL, 0),
(@PATH, 197, -2025.7917, -1284.0762, -1239.7262, NULL, 0),
(@PATH, 198, -2026.4808, -1287.0266, -1239.7262, NULL, 0),
(@PATH, 199, -2027.1694, -1289.9745, -1239.7262, NULL, 0),
(@PATH, 200, -2027.8613, -1292.9369, -1239.7262, NULL, 0),
(@PATH, 201, -2028.5527, -1295.897, -1239.7262, NULL, 0),
(@PATH, 202, -2029.2423, -1298.8497, -1239.7262, NULL, 0),
(@PATH, 203, -2029.932, -1301.8025, -1239.7262, NULL, 0),
(@PATH, 204, -2030.6086, -1304.7506, -1239.7262, NULL, 0),
(@PATH, 205, -2031.2867, -1307.7214, -1239.7262, NULL, 0),
(@PATH, 206, -2031.4736, -1308.5403, -1239.7262, NULL, 11771),
(@PATH, 207, -2032.7653, -1310.9371, -1239.7262, NULL, 0),
(@PATH, 208, -2034.4606, -1309.5197, -1239.7262, NULL, 0),
(@PATH, 209, -2037.1327, -1309.4679, -1239.7262, NULL, 0);

UPDATE `creature` SET `position_x`=-2040.0887, `position_y`=-1309.9312, `position_z`=-1239.7262 WHERE `guid` IN (@CGUID+37, @CGUID+51, @CGUID+42);
UPDATE `creature` SET `position_x`=-2040.0887, `position_y`=-1309.9312, `position_z`=-1239.7262, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
