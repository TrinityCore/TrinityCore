SET @CGUID := 7002993;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1034.78125, 1742.9097900390625, 117.3876571655273437, 6.24521636962890625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+1, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1033.2864990234375, 1769.1197509765625, 119.04681396484375, 6.036331653594970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+2, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1116.470458984375, 1779.3194580078125, 120.537689208984375, 0.659647822380065917, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1101.486083984375, 1826.69970703125, 121.5114288330078125, 4.894130706787109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1083.6475830078125, 1781.30908203125, 118.6386489868164062, 1.326915502548217773, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%) (possible waypoints or random movement)
(@CGUID+5, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1040.640625, 1854.8646240234375, 120.1817550659179687, 5.817926406860351562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1111.15625, 1824.2291259765625, 121.9241561889648437, 5.624743461608886718, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%) (possible waypoints or random movement)
(@CGUID+7, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1128.09375, 1784.15625, 120.2125396728515625, 3.796363353729248046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%) (possible waypoints or random movement)
(@CGUID+8, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1108.3524169921875, 1806.96533203125, 121.0562286376953125, 1.418862104415893554, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+9, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1071.998291015625, 1810.546875, 120.029327392578125, 6.239988327026367187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+10, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1035.6597900390625, 1756.2117919921875, 117.829559326171875, 5.147620201110839843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+11, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1040.28125, 1804.5416259765625, 120.0397491455078125, 4.406663417816162109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+12, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1059.78125, 1865.392333984375, 120.5792922973632812, 3.222604990005493164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+13, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1084.4097900390625, 1707.90283203125, 99.50299072265625, 4.882274150848388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1094.5694580078125, 1737.35595703125, 110.0832366943359375, 0.953478217124938964, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+15, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1212.7083740234375, 1766.2586669921875, 120.9376373291015625, 5.190137863159179687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+16, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1197.1285400390625, 1724.6771240234375, 120.866363525390625, 0.961712121963500976, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+17, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1140.9375, 1745.9913330078125, 120.5797958374023437, 5.321445465087890625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%) (possible waypoints or random movement)
(@CGUID+18, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1167.923583984375, 1728.890625, 121.6950149536132812, 2.788606882095336914, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+19, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1230.220458984375, 1749.9774169921875, 120.4639663696289062, 3.694199562072753906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+20, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1238.7257080078125, 1727.032958984375, 121.0722579956054687, 5.623223304748535156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%) (possible waypoints or random movement)
(@CGUID+21, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1221.204833984375, 1805.407958984375, 121.9377288818359375, 0.393113493919372558, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+22, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1154.859375, 1710.0677490234375, 120.61236572265625, 4.701627731323242187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 126151, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1241.71875, 1842.8489990234375, 135.9288177490234375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Curseformed Familiar (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+24, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1231.8992919921875, 1775.454833984375, 122.6279067993164062, 2.094575166702270507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+25, 126151, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1250.6961669921875, 1800.1492919921875, 123.3650131225585937, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Curseformed Familiar (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+26, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1255.923583984375, 1861.1336669921875, 139.728668212890625, 5.380565166473388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+27, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1297.3489990234375, 1850.1649169921875, 150.184234619140625, 2.186121702194213867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+28, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1271.814208984375, 1793.998291015625, 125.0706329345703125, 3.120194673538208007, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%) (possible waypoints or random movement)
(@CGUID+29, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1316.7222900390625, 1796.0521240234375, 140.433807373046875, 4.277708053588867187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+30, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1357.125, 1766.8211669921875, 134.139678955078125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+31, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1285.8663330078125, 1750.2916259765625, 121.5698165893554687, 0.652110517024993896, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+32, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1294.8819580078125, 1792.0989990234375, 126.5891952514648437, 0.920551061630249023, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+33, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1350.611083984375, 1760.5572509765625, 131.182403564453125, 3.544513702392578125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+34, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1282.0885009765625, 1814.0208740234375, 127.1993789672851562, 2.954456329345703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+35, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1286.8021240234375, 1854.763916015625, 149.333282470703125, 3.608084440231323242, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+36, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1361.3697509765625, 1767.8316650390625, 135.0371551513671875, 2.557877302169799804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+37, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1232.109375, 1825.30908203125, 131.3582763671875, 4.559517383575439453, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+38, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1350.357666015625, 1822.3004150390625, 149.7455902099609375, 5.846167564392089843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+39, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1384.2083740234375, 1834.9774169921875, 158.6360321044921875, 4.861730098724365234, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+40, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1352.013916015625, 1804.0242919921875, 145.02783203125, 1.179173231124877929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+41, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1239.1492919921875, 1772.7379150390625, 122.5526885986328125, 2.02992105484008789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+42, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1274.967041015625, 1746.295166015625, 122.05438232421875, 2.722581386566162109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+43, 126542, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1201.1788330078125, 1942.388916015625, 148.484405517578125, 1.962302446365356445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Ancient Sentinel (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+44, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1185.548583984375, 1803.9254150390625, 121.9543685913085937, 2.109950542449951171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+45, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1249.0225830078125, 1936.001708984375, 152.949371337890625, 1.878711581230163574, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+46, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1253.4896240234375, 1903.564208984375, 142.3534088134765625, 0.063697621226310729, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+47, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1192.982666015625, 1909.4566650390625, 141.1929168701171875, 0.598598599433898925, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+48, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1270.62158203125, 1893.951416015625, 142.1690216064453125, 2.452759027481079101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+49, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1129.795166015625, 1902.71533203125, 136.94219970703125, 1.118233680725097656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+50, 128852, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1287.7899169921875, 1855.7413330078125, 197.218231201171875, 5.255061149597167968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Chillwind Hawk (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+51, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1217.8958740234375, 1830.017333984375, 130.100341796875, 1.180793404579162597, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+52, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1270.5816650390625, 1925.8316650390625, 157.110931396484375, 5.590471744537353515, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+53, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1228.1510009765625, 1911.579833984375, 143.754058837890625, 5.101322650909423828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+54, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1264.9757080078125, 1885.5382080078125, 142.0884552001953125, 4.793601512908935546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+55, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1175.5677490234375, 1898.9774169921875, 139.557159423828125, 5.008866786956787109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+56, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1148.2899169921875, 1878.9444580078125, 135.936614990234375, 5.653156757354736328, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+57, 129742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1215.0694580078125, 1577.654541015625, 109.146148681640625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tufted Craghopper (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 109525 - Sleeping Sleep)
(@CGUID+58, 129742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1193.951416015625, 1563.0885009765625, 109.824005126953125, 3.97253584861755371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tufted Craghopper (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+59, 128852, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1192.689208984375, 1640.3541259765625, 155.4564361572265625, 1.374446272850036621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Chillwind Hawk (Area: Gol Koval - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+60, 129742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1184.7379150390625, 1632.3680419921875, 141.9532318115234375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tufted Craghopper (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+61, 129742, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1182.5572509765625, 1587.1822509765625, 122.7717437744140625, 3.153928756713867187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tufted Craghopper (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+62, 129744, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1181.9097900390625, 1589.3004150390625, 123.137542724609375, 4.008123397827148437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Craghopper Kid (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+63, 128852, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1041.892333984375, 1638.8211669921875, 136.6259307861328125, 0.009241904132068157, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Chillwind Hawk (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+64, 128852, 1643, 8721, 9271, '0', 0, 0, 0, 0, -978.46875, 1928.9774169921875, 212.094757080078125, 4.350938796997070312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Chillwind Hawk (Area: Hunter's Run - Difficulty: 0) CreateObject2
(@CGUID+65, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1330.3316650390625, 1907.513916015625, 158.812469482421875, 1.979643702507019042, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+66, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1345.515625, 1890.65625, 162.130126953125, 1.761441946029663085, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+67, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1379.798583984375, 1869.064208984375, 161.926544189453125, 0.088947802782058715, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+68, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1373.34375, 1911.5972900390625, 169.974761962890625, 6.173984050750732421, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+69, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1323.6510009765625, 1928.4896240234375, 167.51959228515625, 3.879925251007080078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+70, 128876, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1313.4791259765625, 1878.6614990234375, 147.09173583984375, 1.841096162796020507, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Icy Fragment (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+71, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1360.923583984375, 1715.9757080078125, 142.6456298828125, 2.439483642578125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+72, 126355, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1225.18408203125, 1690.0625, 125.1391525268554687, 5.957273483276367187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Awoken Guardian (Area: Gol Koval - Difficulty: 0) CreateObject2
(@CGUID+73, 128703, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1209.046875, 1720.76220703125, 120.9140090942382812, 4.682347774505615234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vengeful Bones (Area: Gol Koval - Difficulty: 0) CreateObject2 (Auras: 155893 - No NPC Damage Below Override Points%)
(@CGUID+74, 139956, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1211.0191650390625, 1763.0042724609375, 120.9384918212890625, 2.04969644546508789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Thornguard Shieldpaw (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+75, 139954, 1643, 8721, 9134, '0', 0, 0, 0, 0, -1127.8507080078125, 1905.420166015625, 137.038177490234375, 4.251857757568359375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Thornguard Ironclaw (Area: Gol Koval - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Awoken Guardian
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Awoken Guardian
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''); -- Awoken Guardian

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (127979,128707,129744,126151,143689,143686,143687,143688,129742,128876,126542,128852) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127979 AND `DifficultyID`=0); -- 127979 (Lost Goat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=60568 WHERE (`Entry`=128707 AND `DifficultyID`=0); -- 128707 (Rimestone) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=129744 AND `DifficultyID`=0); -- 129744 (Craghopper Kid) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=126151 AND `DifficultyID`=0); -- 126151 (Curseformed Familiar) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=60568 WHERE (`Entry`=143689 AND `DifficultyID`=0); -- 143689 (Runic Ward) - Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=60568 WHERE (`Entry`=143686 AND `DifficultyID`=0); -- 143686 (Runic Ward) - Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=60568 WHERE (`Entry`=143687 AND `DifficultyID`=0); -- 143687 (Runic Ward) - Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=60568 WHERE (`Entry`=143688 AND `DifficultyID`=0); -- 143688 (Runic Ward) - Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=129742 AND `DifficultyID`=0); -- 129742 (Tufted Craghopper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=60568 WHERE (`Entry`=128876 AND `DifficultyID`=0); -- 128876 (Icy Fragment) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=187, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=126542 AND `DifficultyID`=0); -- 126542 (Ancient Sentinel) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60568 WHERE (`Entry`=128852 AND `DifficultyID`=0); -- 128852 (Chillwind Hawk) - CanSwim, Floating

 -- Vengeful Bones smart ai
SET @ENTRY := 128703;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 266050, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 266050 on self', '');

UPDATE `creature` SET `StringID` = 'ChannelWitch' WHERE `guid` IN (@CGUID+73,@CGUID+27,@CGUID+48,@CGUID+55);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 128703 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 128703, 0, 0, 58, 1, 0, 0, 0, 'ChannelWitch', 0, 'Action invoker has StringID ChannelWitch');

-- Path for Ancient Sentinel
SET @MOVERGUID := @CGUID+43;
SET @ENTRY := 126542;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ancient Sentinel - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1209.066, 1961.4948, 151.31216, NULL, 0),
(@PATH, 1, -1209.8438, 1955.507, 150.74751, NULL, 0),
(@PATH, 2, -1211.3524, 1947.2344, 149.54195, NULL, 0),
(@PATH, 3, -1211.3629, 1939.5695, 148.81747, NULL, 0),
(@PATH, 4, -1210.375, 1936.5747, 148.48552, NULL, 0),
(@PATH, 5, -1204.6094, 1936.3368, 147.69695, NULL, 0),
(@PATH, 6, -1195.3055, 1937.8837, 147.24016, NULL, 0),
(@PATH, 7, -1190.3455, 1940.7396, 146.94685, NULL, 0),
(@PATH, 8, -1194.4098, 1945.1632, 147.98296, NULL, 0),
(@PATH, 9, -1196.4462, 1950.8281, 148.7295, NULL, 0),
(@PATH, 10, -1198.8524, 1957.9653, 150.00809, NULL, 0),
(@PATH, 11, -1201.092, 1963.0538, 150.52313, NULL, 0),
(@PATH, 12, -1205.8646, 1963.1666, 151.31009, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+13;
SET @ENTRY := 126355;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1081.9618, 1705.1719, 99.62465, NULL, 0),
(@PATH, 1, -1083.6146, 1703.2673, 99.285904, NULL, 0),
(@PATH, 2, -1080.9028, 1692.276, 99.3889, NULL, 0),
(@PATH, 3, -1079.533, 1675.9584, 98.94983, NULL, 0),
(@PATH, 4, -1077.4392, 1669.5035, 98.662056, NULL, 0),
(@PATH, 5, -1075.7327, 1658.8177, 98.53048, NULL, 0),
(@PATH, 6, -1073.8837, 1646.2986, 96.70059, NULL, 0),
(@PATH, 7, -1075.7517, 1660.4497, 98.475685, NULL, 0),
(@PATH, 8, -1077.4913, 1674.106, 98.97519, NULL, 0),
(@PATH, 9, -1079.606, 1691.1562, 99.41614, NULL, 0),
(@PATH, 10, -1080.3317, 1699.6615, 99.63635, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 126355;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1075.8906, 1861.8403, 121.36363, NULL, 0),
(@PATH, 1, -1088.3611, 1862.3091, 121.98203, NULL, 0),
(@PATH, 2, -1101.7604, 1863.7257, 122.51147, NULL, 0),
(@PATH, 3, -1113.7673, 1866.231, 125.20876, NULL, 0),
(@PATH, 4, -1126.0903, 1869.224, 129.64465, NULL, 0),
(@PATH, 5, -1119.5, 1871.2795, 128.03842, NULL, 0),
(@PATH, 6, -1108.9149, 1868.6111, 124.94176, NULL, 0),
(@PATH, 7, -1093.6337, 1866.4757, 122.78601, NULL, 0),
(@PATH, 8, -1079.5173, 1865.7344, 121.96948, NULL, 0),
(@PATH, 9, -1064.3038, 1866.4062, 120.73435, NULL, 0),
(@PATH, 10, -1067.9062, 1864.7327, 121.0619, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 126355;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1251.3385, 1903.7014, 142.15001, NULL, 0),
(@PATH, 1, -1247.3906, 1896.8177, 142.14017, NULL, 0),
(@PATH, 2, -1246.0087, 1889.5608, 141.95462, NULL, 0),
(@PATH, 3, -1241.9323, 1886.8455, 141.96474, NULL, 0),
(@PATH, 4, -1237.0798, 1884.2709, 141.59334, NULL, 0),
(@PATH, 5, -1229.941, 1882.106, 140.6318, NULL, 0),
(@PATH, 6, -1224.7223, 1880.3802, 140.62802, NULL, 0),
(@PATH, 7, -1221.2483, 1881.1771, 140.631, NULL, 0),
(@PATH, 8, -1219.4341, 1884.8906, 140.77155, NULL, 0),
(@PATH, 9, -1219.0139, 1889.9653, 141.01201, NULL, 0),
(@PATH, 10, -1218.901, 1896.3716, 141.68942, NULL, 0),
(@PATH, 11, -1219.3038, 1903.0035, 142.4932, NULL, 0),
(@PATH, 12, -1221.8611, 1907.0452, 142.88771, NULL, 0),
(@PATH, 13, -1225.8959, 1910.9966, 143.46692, NULL, 0),
(@PATH, 14, -1232.3541, 1914.2031, 144.10553, NULL, 0),
(@PATH, 15, -1239, 1914.4149, 143.12605, NULL, 0),
(@PATH, 16, -1241.2848, 1910.2535, 142.12247, NULL, 0),
(@PATH, 17, -1247.9567, 1906.4896, 142.14816, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+21;
SET @ENTRY := 126355;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1223.3716, 1800.1702, 121.75391, NULL, 0),
(@PATH, 1, -1213.8785, 1808.4462, 122.63496, NULL, 0),
(@PATH, 2, -1204.3334, 1806.8698, 122.07057, NULL, 0),
(@PATH, 3, -1191.1007, 1804.8767, 122.07613, NULL, 0),
(@PATH, 4, -1186.731, 1797.8802, 121.68462, NULL, 0),
(@PATH, 5, -1198.1476, 1787.4166, 122.0764, NULL, 0),
(@PATH, 6, -1204.1997, 1787.2361, 122.28303, NULL, 0),
(@PATH, 7, -1215.066, 1793.8368, 122.5993, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+2;
SET @ENTRY := 126355;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1103.5087, 1788.1754, 119.51978, NULL, 0),
(@PATH, 1, -1105.7812, 1787.6094, 119.44181, NULL, 0),
(@PATH, 2, -1102.0781, 1782.8942, 119.29555, NULL, 0),
(@PATH, 3, -1096.9305, 1777.1423, 118.83356, NULL, 0),
(@PATH, 4, -1092.8594, 1771.8993, 118.17521, NULL, 0),
(@PATH, 5, -1089.5973, 1767.6476, 116.9748, NULL, 0),
(@PATH, 6, -1085.2656, 1762.0798, 116.36243, NULL, 0),
(@PATH, 7, -1082.125, 1757.0868, 115.35726, NULL, 0),
(@PATH, 8, -1081.0712, 1756.1302, 115.07122, NULL, 0),
(@PATH, 9, -1080.7639, 1759.1997, 115.98436, NULL, 0),
(@PATH, 10, -1082.3993, 1762.566, 116.71064, NULL, 0),
(@PATH, 11, -1086.1442, 1768.0243, 117.10547, NULL, 0),
(@PATH, 12, -1088.8108, 1772.9584, 117.99026, NULL, 0),
(@PATH, 13, -1094.2396, 1778.8524, 118.92107, NULL, 0),
(@PATH, 14, -1098.6163, 1783.1805, 119.17063, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 126355;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1237.3959, 1783.7535, 122.23377, NULL, 0),
(@PATH, 1, -1241.2778, 1789.9445, 121.90664, NULL, 0),
(@PATH, 2, -1244.441, 1795.8507, 121.87764, NULL, 0),
(@PATH, 3, -1246.8906, 1800.0365, 122.73354, NULL, 0),
(@PATH, 4, -1252.4358, 1805.4462, 123.26207, NULL, 0),
(@PATH, 5, -1257.4132, 1809.2361, 124.20114, NULL, 0),
(@PATH, 6, -1264.9653, 1812.9098, 125.19413, NULL, 0),
(@PATH, 7, -1273.8577, 1815.6041, 125.8502, NULL, 3432),
(@PATH, 8, -1264.9653, 1812.9098, 125.19413, NULL, 0),
(@PATH, 9, -1257.4132, 1809.2361, 124.20114, NULL, 0),
(@PATH, 10, -1252.4358, 1805.4462, 123.26207, NULL, 0),
(@PATH, 11, -1246.8906, 1800.0365, 122.73354, NULL, 0),
(@PATH, 12, -1244.441, 1795.8507, 121.87764, NULL, 0),
(@PATH, 13, -1241.2778, 1789.9445, 121.90664, NULL, 0),
(@PATH, 14, -1237.3959, 1783.7535, 122.23377, NULL, 0),
(@PATH, 15, -1234.9913, 1780.8055, 122.64018, NULL, 0),
(@PATH, 16, -1233.0104, 1777.3611, 122.671555, NULL, 3090);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+40;
SET @ENTRY := 126355;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1350.8317, 1806.8872, 145.49333, NULL, 0),
(@PATH, 1, -1348.9062, 1809, 145.69704, NULL, 0),
(@PATH, 2, -1345.375, 1814.5243, 146.54355, NULL, 0),
(@PATH, 3, -1342.7899, 1818.4913, 147.20888, NULL, 0),
(@PATH, 4, -1346.3142, 1820.1666, 148.25186, NULL, 0),
(@PATH, 5, -1349.1562, 1821.5452, 149.2094, NULL, 0),
(@PATH, 6, -1353.632, 1815.099, 148.33435, NULL, 0),
(@PATH, 7, -1356.6024, 1810.8942, 147.77386, NULL, 0),
(@PATH, 8, -1356.1666, 1809.0104, 147.16388, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+34;
SET @ENTRY := 126355;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1289.2031, 1815.368, 129.83357, NULL, 0),
(@PATH, 1, -1296.5312, 1819.6754, 134.31305, NULL, 0),
(@PATH, 2, -1301.7188, 1822.0555, 137.29845, NULL, 0),
(@PATH, 3, -1309.9688, 1828.6198, 139.51703, NULL, 0),
(@PATH, 4, -1317.0226, 1836.4548, 141.28806, NULL, 0),
(@PATH, 5, -1323.3438, 1848.2622, 142.25185, NULL, 0),
(@PATH, 6, -1325.6649, 1853.6719, 143.14156, NULL, 0),
(@PATH, 7, -1324.4271, 1859.2223, 144.61662, NULL, 0),
(@PATH, 8, -1321.7361, 1862.8524, 145.6321, NULL, 0),
(@PATH, 9, -1325.0851, 1858.6216, 144.42902, NULL, 0),
(@PATH, 10, -1324.5538, 1849.0555, 142.32538, NULL, 0),
(@PATH, 11, -1318.9479, 1838.151, 141.6253, NULL, 0),
(@PATH, 12, -1311.7812, 1829.3541, 139.73401, NULL, 0),
(@PATH, 13, -1300.6285, 1820.4254, 136.43742, NULL, 0),
(@PATH, 14, -1293.8091, 1817.7639, 132.58315, NULL, 0),
(@PATH, 15, -1289.1267, 1815.3142, 129.7854, NULL, 0),
(@PATH, 16, -1285.5365, 1814.7709, 128.31073, NULL, 0),
(@PATH, 17, -1281.8699, 1814.1737, 126.78789, NULL, 0),
(@PATH, 18, -1285.5365, 1814.7709, 128.31073, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+5;
SET @ENTRY := 126355;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1042.3663, 1855.731, 120.31956, NULL, 0),
(@PATH, 1, -1040.6406, 1854.8646, 120.181755, NULL, 0),
(@PATH, 2, -1038.9149, 1853.9983, 120.04395, NULL, 0),
(@PATH, 3, -1036.1754, 1848.7935, 119.62758, NULL, 0),
(@PATH, 4, -1032.5747, 1840.441, 120.05814, NULL, 0),
(@PATH, 5, -1030.0416, 1833.1702, 120.57072, NULL, 0),
(@PATH, 6, -1028.4584, 1828.5104, 121.02192, NULL, 0),
(@PATH, 7, -1030.5608, 1828.7396, 120.79874, NULL, 0),
(@PATH, 8, -1032.9323, 1833.6945, 120.25825, NULL, 0),
(@PATH, 9, -1036.0486, 1839.2916, 120.02398, NULL, 0),
(@PATH, 10, -1039.3611, 1846.9219, 119.84668, NULL, 0),
(@PATH, 11, -1041.691, 1851.7118, 120.0952, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+69;
SET @ENTRY := 126355;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1326.1979, 1926.1719, 166.75882, NULL, 0),
(@PATH, 1, -1329.1146, 1923.6302, 165.65039, NULL, 0),
(@PATH, 2, -1341, 1917.7101, 163.59229, NULL, 0),
(@PATH, 3, -1346.3091, 1916.0885, 163.90372, NULL, 0),
(@PATH, 4, -1351.4375, 1915.6841, 164.97617, NULL, 0),
(@PATH, 5, -1359.2865, 1914.4618, 166.83908, NULL, 0),
(@PATH, 6, -1362.5348, 1913.6024, 167.82512, NULL, 0),
(@PATH, 7, -1358.8976, 1915.5555, 166.71907, NULL, 0),
(@PATH, 8, -1353.7969, 1916, 165.46562, NULL, 0),
(@PATH, 9, -1348.6562, 1916.2882, 164.41605, NULL, 0),
(@PATH, 10, -1344.9098, 1916.9271, 163.7987, NULL, 0),
(@PATH, 11, -1341.9305, 1918.231, 163.89911, NULL, 0),
(@PATH, 12, -1329.9618, 1924.132, 165.71834, NULL, 0),
(@PATH, 13, -1326.6406, 1926.1649, 166.72566, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+67;
SET @ENTRY := 126355;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1375.6129, 1869.4375, 160.89069, NULL, 0),
(@PATH, 1, -1368.342, 1869.908, 159.26562, NULL, 0),
(@PATH, 2, -1360.8142, 1869.1666, 157.28548, NULL, 0),
(@PATH, 3, -1354.1875, 1868.5104, 155.45866, NULL, 0),
(@PATH, 4, -1348.0642, 1867.4462, 153.58908, NULL, 0),
(@PATH, 5, -1342.5052, 1868.0712, 151.20425, NULL, 0),
(@PATH, 6, -1333.132, 1867.8108, 148.73439, NULL, 0),
(@PATH, 7, -1329.1823, 1867.6736, 147.9771, NULL, 0),
(@PATH, 8, -1334.0625, 1867.9115, 148.93443, NULL, 0),
(@PATH, 9, -1340.2361, 1868.9115, 150.47694, NULL, 0),
(@PATH, 10, -1347.6875, 1869.9757, 153.6562, NULL, 0),
(@PATH, 11, -1354.118, 1870.1163, 155.6625, NULL, 0),
(@PATH, 12, -1364.3212, 1870.4236, 158.43823, NULL, 0),
(@PATH, 13, -1375.2848, 1869.6666, 160.8633, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+71;
SET @ENTRY := 126355;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1365.9601, 1720.2361, 143.75153, NULL, 0),
(@PATH, 1, -1371.1389, 1725.6685, 143.85701, NULL, 0),
(@PATH, 2, -1375.7466, 1731.3473, 143.5663, NULL, 0),
(@PATH, 3, -1379.9271, 1739.8872, 143.55228, NULL, 0),
(@PATH, 4, -1382.4705, 1748.1007, 142.97827, NULL, 0),
(@PATH, 5, -1382.7274, 1754.5747, 141.9106, NULL, 0),
(@PATH, 6, -1380.8698, 1761.4531, 139.96083, NULL, 0),
(@PATH, 7, -1382.849, 1757.3594, 141.53539, NULL, 0),
(@PATH, 8, -1384.1442, 1751.3004, 142.70317, NULL, 0),
(@PATH, 9, -1381.4548, 1736.6719, 143.97075, NULL, 0),
(@PATH, 10, -1373.8385, 1723.4844, 143.63547, NULL, 0),
(@PATH, 11, -1367.9827, 1717.6493, 143.66003, NULL, 0),
(@PATH, 12, -1365.7135, 1716.0017, 143.40904, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+22;
SET @ENTRY := 126355;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1154.8246, 1713.3004, 120.82369, NULL, 0),
(@PATH, 1, -1154.8594, 1710.0677, 120.612366, NULL, 0),
(@PATH, 2, -1154.8942, 1706.8351, 120.40104, NULL, 0),
(@PATH, 3, -1153.7604, 1703.7483, 119.7309, NULL, 0),
(@PATH, 4, -1152.9601, 1697.5209, 119.48785, NULL, 0),
(@PATH, 5, -1153.1771, 1692.0938, 119.42014, NULL, 0),
(@PATH, 6, -1153.7031, 1686.0469, 119.88194, NULL, 0),
(@PATH, 7, -1154.7344, 1682.6094, 120.29379, NULL, 0),
(@PATH, 8, -1155.2587, 1685.217, 120.4375, NULL, 0),
(@PATH, 9, -1154.7048, 1690.3959, 119.89063, NULL, 0),
(@PATH, 10, -1154.9635, 1697.901, 119.43924, NULL, 0),
(@PATH, 11, -1155.9375, 1702.724, 119.50174, NULL, 0),
(@PATH, 12, -1156.8524, 1706.8959, 120.10069, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Awoken Guardian
SET @MOVERGUID := @CGUID+72;
SET @ENTRY := 126355;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Awoken Guardian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1222.3281, 1689.0973, 124.15833, NULL, 0),
(@PATH, 1, -1218.7535, 1692.2118, 123.28866, NULL, 0),
(@PATH, 2, -1212.0365, 1692.6927, 122.17236, NULL, 0),
(@PATH, 3, -1204.0399, 1690.8524, 120.73438, NULL, 0),
(@PATH, 4, -1196.7969, 1688.5452, 120.5386, NULL, 0),
(@PATH, 5, -1192.8993, 1687.1805, 120.79899, NULL, 0),
(@PATH, 6, -1184.4185, 1692.9254, 120.87279, NULL, 0),
(@PATH, 7, -1181.4098, 1695.3385, 120.58054, NULL, 0),
(@PATH, 8, -1183.9548, 1693.9062, 120.80387, NULL, 0),
(@PATH, 9, -1190.9202, 1691.5365, 120.60667, NULL, 0),
(@PATH, 10, -1195.0885, 1691.4896, 120.48911, NULL, 0),
(@PATH, 11, -1200.6007, 1691.8351, 120.50944, NULL, 0),
(@PATH, 12, -1204.2656, 1692.1129, 120.7447, NULL, 0),
(@PATH, 13, -1209.7986, 1692.7205, 121.77488, NULL, 0),
(@PATH, 14, -1218.3195, 1691.1285, 123.19679, NULL, 0),
(@PATH, 15, -1222.6632, 1689.8455, 124.22987, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+50;
SET @ENTRY := 128852;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5486, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1277.715, 1839.0352, 197.21823, NULL, 0),
(@PATH, 1, -1262.0138, 1827.456, 197.21823, NULL, 0),
(@PATH, 2, -1243.0765, 1822.7671, 197.21823, NULL, 0),
(@PATH, 3, -1223.7865, 1825.6819, 197.21823, NULL, 0),
(@PATH, 4, -1207.0803, 1835.7568, 197.21823, NULL, 0),
(@PATH, 5, -1195.5013, 1851.4581, 197.21823, NULL, 0),
(@PATH, 6, -1190.8123, 1870.3953, 197.21823, NULL, 0),
(@PATH, 7, -1193.7272, 1889.6853, 197.21823, NULL, 0),
(@PATH, 8, -1203.8021, 1906.3915, 197.21823, NULL, 0),
(@PATH, 9, -1219.5033, 1917.9706, 197.21823, NULL, 0),
(@PATH, 10, -1238.4404, 1922.6595, 197.21823, NULL, 0),
(@PATH, 11, -1257.7306, 1919.7446, 197.21823, NULL, 0),
(@PATH, 12, -1274.4368, 1909.6697, 197.21823, NULL, 0),
(@PATH, 13, -1286.0157, 1893.9685, 197.21823, NULL, 0),
(@PATH, 14, -1290.7047, 1875.0314, 197.21823, NULL, 0),
(@PATH, 15, -1287.7899, 1855.7413, 197.21823, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+59;
SET @ENTRY := 128852;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5486, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1188.8832, 1659.4883, 155.45644, NULL, 0),
(@PATH, 1, -1178.0446, 1675.7095, 155.45644, NULL, 0),
(@PATH, 2, -1161.8234, 1686.5481, 155.45644, NULL, 0),
(@PATH, 3, -1142.6892, 1690.3541, 155.45644, NULL, 0),
(@PATH, 4, -1123.555, 1686.5481, 155.45644, NULL, 0),
(@PATH, 5, -1107.3339, 1675.7095, 155.45644, NULL, 0),
(@PATH, 6, -1096.4952, 1659.4883, 155.45644, NULL, 0),
(@PATH, 7, -1092.6892, 1640.3541, 155.45644, NULL, 0),
(@PATH, 8, -1096.4952, 1621.22, 155.45644, NULL, 0),
(@PATH, 9, -1107.3339, 1604.9988, 155.45644, NULL, 0),
(@PATH, 10, -1123.555, 1594.1602, 155.45644, NULL, 0),
(@PATH, 11, -1142.6892, 1590.3541, 155.45644, NULL, 0),
(@PATH, 12, -1161.8234, 1594.1602, 155.45644, NULL, 0),
(@PATH, 13, -1178.0446, 1604.9988, 155.45644, NULL, 0),
(@PATH, 14, -1188.8832, 1621.22, 155.45644, NULL, 0),
(@PATH, 15, -1192.6892, 1640.3541, 155.45644, NULL, 0),
(@PATH, 16, -1188.8832, 1659.4883, 155.45644, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+63;
SET @ENTRY := 128852;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5486, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1022.38416, 1639.0015, 136.62593, NULL, 0),
(@PATH, 1, -1004.42993, 1646.6337, 136.62593, NULL, 0),
(@PATH, 2, -990.76306, 1660.5555, 136.62593, NULL, 0),
(@PATH, 3, -983.46423, 1678.6478, 136.62593, NULL, 0),
(@PATH, 4, -983.6446, 1698.156, 136.62593, NULL, 0),
(@PATH, 5, -991.27673, 1716.1102, 136.62593, NULL, 0),
(@PATH, 6, -1005.1986, 1729.7771, 136.62593, NULL, 0),
(@PATH, 7, -1023.2909, 1737.0759, 136.62593, NULL, 0),
(@PATH, 8, -1042.7991, 1736.8955, 136.62593, NULL, 0),
(@PATH, 9, -1060.7533, 1729.2634, 136.62593, NULL, 0),
(@PATH, 10, -1074.4202, 1715.3414, 136.62593, NULL, 0),
(@PATH, 11, -1081.719, 1697.2493, 136.62593, NULL, 0),
(@PATH, 12, -1081.5386, 1677.7411, 136.62593, NULL, 0),
(@PATH, 13, -1073.9065, 1659.7869, 136.62593, NULL, 0),
(@PATH, 14, -1059.9846, 1646.12, 136.62593, NULL, 0),
(@PATH, 15, -1041.8923, 1638.8212, 136.62593, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+64;
SET @ENTRY := 128852;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5486, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -985.36774, 1910.729, 212.09476, NULL, 0),
(@PATH, 1, -984.7582, 1891.2295, 212.09476, NULL, 0),
(@PATH, 2, -976.7329, 1873.4475, 212.09476, NULL, 0),
(@PATH, 3, -962.5137, 1860.0903, 212.09476, NULL, 0),
(@PATH, 4, -944.2652, 1853.1913, 212.09476, NULL, 0),
(@PATH, 5, -924.7657, 1853.8009, 212.09476, NULL, 0),
(@PATH, 6, -906.98376, 1861.8262, 212.09476, NULL, 0),
(@PATH, 7, -893.6265, 1876.0454, 212.09476, NULL, 0),
(@PATH, 8, -886.72754, 1894.294, 212.09476, NULL, 0),
(@PATH, 9, -887.3371, 1913.7933, 212.09476, NULL, 0),
(@PATH, 10, -895.3624, 1931.5753, 212.09476, NULL, 0),
(@PATH, 11, -909.58167, 1944.9325, 212.09476, NULL, 0),
(@PATH, 12, -927.83014, 1951.8315, 212.09476, NULL, 0),
(@PATH, 13, -947.32965, 1951.2219, 212.09476, NULL, 0),
(@PATH, 14, -965.1116, 1943.1967, 212.09476, NULL, 0),
(@PATH, 15, -978.46875, 1928.9774, 212.09476, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Vengeful Bones
SET @MOVERGUID := @CGUID+20;
SET @ENTRY := 128703;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Vengeful Bones - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1237.0278, 1725.7153, 121.11492, NULL, 0),
(@PATH, 1, -1234.2466, 1723.3438, 121.18638, NULL, 0),
(@PATH, 2, -1232.401, 1720.4757, 121.38129, NULL, 0),
(@PATH, 3, -1230.0591, 1715.6129, 121.87739, NULL, 0),
(@PATH, 4, -1228.0399, 1711.3541, 121.82422, NULL, 0),
(@PATH, 5, -1230.9166, 1714.8524, 122.19358, NULL, 0),
(@PATH, 6, -1232.6927, 1718.9202, 121.70592, NULL, 0),
(@PATH, 7, -1234.6285, 1722.1736, 121.34458, NULL, 0),
(@PATH, 8, -1237.0781, 1725.6423, 121.12313, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
