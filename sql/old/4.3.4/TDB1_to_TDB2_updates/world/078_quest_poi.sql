DELETE FROM `quest_poi` WHERE (`questid`=8789 AND `id`=1) OR (`questid`=8790 AND `id`=1);

DELETE FROM `quest_poi` WHERE `questid` IN (27123, 28853, 28854, 26245, 28528, 27440, 27445, 27444, 28708, 26173, 29528, 29594, 29529, 29861, 29860, 28826, 24432, 25281, 25405, 25357, 25546, 28760, 28814);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(27123, 0, -1, 646, 640, 0, 0, 1), -- Deepholm, Realm of Earth
(28853, 2, 4, 670, 757, 1, 0, 7), -- Kill the Courier
(28853, 3, -1, 670, 757, 1, 0, 7), -- Kill the Courier
(28854, 0, 0, 670, 757, 1, 0, 7), -- Closing a Dark Chapter
(28854, 1, -1, 670, 757, 1, 0, 7), -- Closing a Dark Chapter
(26245, 0, -1, 646, 640, 0, 0, 1), -- Gunship Down
(26245, 1, 0, 646, 640, 0, 0, 1), -- Gunship Down
(26245, 2, 1, 646, 640, 0, 0, 1), -- Gunship Down
(26245, 3, 2, 646, 640, 0, 0, 1), -- Gunship Down
(8789, 1, -1, 1, 261, 0, 0, 3), -- Imperial Qiraji Armaments
(8790, 1, -1, 1, 261, 0, 0, 3), -- Imperial Qiraji Regalia
(28528, 0, -1, 1, 261, 0, 0, 1), -- Hero's Call: Silithus!
(27440, 0, 0, 229, 721, 1, 0, 7), -- Trolls, Ogres, and Orcs, Oh My!
(27440, 1, 1, 229, 721, 3, 0, 7), -- Trolls, Ogres, and Orcs, Oh My!
(27440, 2, 2, 229, 721, 6, 0, 7), -- Trolls, Ogres, and Orcs, Oh My!
(27440, 3, -1, 229, 721, 4, 0, 7), -- Trolls, Ogres, and Orcs, Oh My!
(27445, 0, -1, 229, 721, 4, 0, 7), -- General Drakkisath, Hand of Nefarian
(27445, 1, 0, 229, 721, 7, 0, 7), -- General Drakkisath, Hand of Nefarian
(27444, 0, 0, 229, 721, 1, 0, 1), -- The False Warchief
(27444, 1, -1, 229, 721, 1, 0, 1), -- The False Warchief
(28708, 0, -1, 530, 465, 0, 0, 1), -- Hero's Call: Outland!
(26173, 0, 0, 0, 19, 0, 0, 1), -- Protecting Our Rear
(26173, 1, 1, 0, 19, 0, 0, 1), -- Protecting Our Rear
(26173, 2, 2, 0, 19, 0, 0, 1), -- Protecting Our Rear
(26173, 3, -1, 0, 19, 0, 0, 1), -- Protecting Our Rear
(29528, 0, -1, 543, 797, 1, 0, 7), -- War on the Ramparts
(29528, 1, 4, 543, 797, 1, 0, 7), -- War on the Ramparts
(29528, 2, 5, 543, 797, 1, 0, 7), -- War on the Ramparts
(29594, 0, -1, 543, 797, 1, 0, 3), -- Hitting Them Where It Hurts
(29594, 1, 4, 543, 797, 1, 0, 7), -- Hitting Them Where It Hurts
(29594, 2, 4, 543, 797, 1, 0, 7), -- Hitting Them Where It Hurts
(29594, 3, 4, 543, 797, 1, 0, 7), -- Hitting Them Where It Hurts
(29594, 4, 4, 543, 797, 1, 0, 7), -- Hitting Them Where It Hurts
(29594, 5, 4, 543, 797, 1, 0, 7), -- Hitting Them Where It Hurts
(29594, 6, 4, 543, 797, 1, 0, 7), -- Hitting Them Where It Hurts
(29529, 0, 4, 543, 797, 1, 0, 3), -- Demons in the Citadel
(29529, 1, -1, 543, 797, 1, 0, 3), -- Demons in the Citadel
(29861, 0, -1, 602, 525, 1, 0, 7), -- Whatever it Takes!
(29861, 1, 4, 602, 525, 2, 0, 7), -- Whatever it Takes!
(29861, 2, -1, 602, 525, 2, 0, 7), -- Whatever it Takes!
(29860, 1, 0, 602, 525, 2, 0, 7), -- Diametrically Opposed
(29860, 2, -1, 602, 525, 2, 0, 7), -- Diametrically Opposed
(28826, 0, -1, 0, 301, 0, 0, 1), -- The Eye of the Storm
(28826, 1, 0, 0, 301, 0, 0, 7), -- The Eye of the Storm
(24432, 0, 5, 0, 610, 0, 0, 1), -- Sea Legs
(24432, 1, -1, 0, 610, 0, 0, 1), -- Sea Legs
(25281, 0, 0, 0, 610, 0, 0, 1), -- Pay It Forward
(25281, 1, -1, 0, 610, 0, 0, 1), -- Pay It Forward
(25405, 0, -1, 0, 610, 0, 0, 1), -- Rest For the Weary
(25357, 0, 0, 0, 610, 0, 0, 3), -- Buy Us Some Time
(25357, 2, -1, 0, 610, 0, 0, 1), -- Buy Us Some Time
(25546, 0, 4, 0, 610, 0, 0, 1), -- Traveling on Our Stomachs
(25546, 1, -1, 0, 610, 0, 0, 1), -- Traveling on Our Stomachs
(28760, 3, 0, 657, 769, 1, 0, 7), -- Vengeance for Orsis
(28760, 4, -1, 657, 769, 1, 0, 7), -- Vengeance for Orsis
(28814, 0, 0, 725, 768, 1, 0, 1), -- Followers and Leaders
(28814, 3, -1, 725, 768, 1, 0, 1), -- Followers and Leaders
(28814, 4, 1, 725, 768, 1, 0, 7); -- Followers and Leaders


DELETE FROM `quest_poi_points` WHERE (`questId`=27123 AND `id`=0) OR (`questId`=28853 AND `id`=2) OR (`questId`=28853 AND `id`=3) OR (`questId`=28854 AND `id`=0) OR (`questId`=28854 AND `id`=1) OR (`questId`=26245 AND `id`=0) OR (`questId`=26245 AND `id`=1) OR (`questId`=26245 AND `id`=2) OR (`questId`=26245 AND `id`=3) OR (`questId`=28528 AND `id`=0) OR (`questId`=27440 AND `id`=0) OR (`questId`=27440 AND `id`=1) OR (`questId`=27440 AND `id`=2) OR (`questId`=27440 AND `id`=3) OR (`questId`=27445 AND `id`=0) OR (`questId`=27445 AND `id`=1) OR (`questId`=27444 AND `id`=0) OR (`questId`=27444 AND `id`=1) OR (`questId`=28708 AND `id`=0) OR (`questId`=26173 AND `id`=0) OR (`questId`=26173 AND `id`=1) OR (`questId`=26173 AND `id`=2) OR (`questId`=26173 AND `id`=3) OR (`questId`=29528 AND `id`=0) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=1) OR (`questId`=29528 AND `id`=2) OR (`questId`=29594 AND `id`=0) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=1) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=2) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=3) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=4) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=5) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29594 AND `id`=6) OR (`questId`=29529 AND `id`=0) OR (`questId`=29529 AND `id`=1) OR (`questId`=29861 AND `id`=1) OR (`questId`=29861 AND `id`=2) OR (`questId`=29860 AND `id`=1) OR (`questId`=29860 AND `id`=2) OR (`questId`=28826 AND `id`=0) OR (`questId`=28826 AND `id`=1) OR (`questId`=24432 AND `id`=0) OR (`questId`=24432 AND `id`=0) OR (`questId`=24432 AND `id`=0) OR (`questId`=24432 AND `id`=0) OR (`questId`=24432 AND `id`=0) OR (`questId`=24432 AND `id`=0) OR (`questId`=24432 AND `id`=1) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=0) OR (`questId`=25281 AND `id`=1) OR (`questId`=25405 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=0) OR (`questId`=25357 AND `id`=2) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=0) OR (`questId`=25546 AND `id`=1) OR (`questId`=28760 AND `id`=3) OR (`questId`=28760 AND `id`=4) OR (`questId`=28814 AND `id`=0) OR (`questId`=28814 AND `id`=3) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4) OR (`questId`=28814 AND `id`=4);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(27123, 0, 0, 996, 521), -- Deepholm, Realm of Earth
(28853, 2, 0, -412, -686), -- Kill the Courier
(28853, 3, 0, -614, -254), -- Kill the Courier
(28854, 0, 0, -734, -828), -- Closing a Dark Chapter
(28854, 1, 0, -606, -257), -- Closing a Dark Chapter
(26245, 0, 0, 996, 521), -- Gunship Down
(26245, 1, 0, 248, 210), -- Gunship Down
(26245, 2, 0, 253, 169), -- Gunship Down
(26245, 3, 0, 220, 170), -- Gunship Down
(28528, 0, 0, -6848, 756), -- Hero's Call: Silithus!
(27440, 0, 0, -23, -457), -- Trolls, Ogres, and Orcs, Oh My!
(27440, 1, 0, -43, -333), -- Trolls, Ogres, and Orcs, Oh My!
(27440, 2, 0, -52, -500), -- Trolls, Ogres, and Orcs, Oh My!
(27440, 3, 0, 71, -267), -- Trolls, Ogres, and Orcs, Oh My!
(27445, 0, 0, 71, -267), -- General Drakkisath, Hand of Nefarian
(27445, 1, 0, 12, -300), -- General Drakkisath, Hand of Nefarian
(27444, 0, 0, 159, -444), -- The False Warchief
(27444, 1, 0, 69, -260), -- The False Warchief
(28708, 0, 0, -266, 1029), -- Hero's Call: Outland!
(26173, 0, 0, -11751, -2802), -- Protecting Our Rear
(26173, 1, 0, -11637, -3389), -- Protecting Our Rear
(26173, 2, 0, -11615, -3073), -- Protecting Our Rear
(26173, 3, 0, -11815, -3196), -- Protecting Our Rear
(29528, 0, 0, -1351, 1653), -- War on the Ramparts
(29528, 1, 0, -1187, 1439), -- War on the Ramparts
(29528, 1, 1, -1176, 1444), -- War on the Ramparts
(29528, 1, 2, -1148, 1488), -- War on the Ramparts
(29528, 1, 3, -1148, 1494), -- War on the Ramparts
(29528, 1, 4, -1148, 1503), -- War on the Ramparts
(29528, 1, 5, -1154, 1515), -- War on the Ramparts
(29528, 1, 6, -1165, 1517), -- War on the Ramparts
(29528, 1, 7, -1175, 1516), -- War on the Ramparts
(29528, 1, 8, -1194, 1474), -- War on the Ramparts
(29528, 1, 9, -1196, 1467), -- War on the Ramparts
(29528, 1, 10, -1196, 1454), -- War on the Ramparts
(29528, 1, 11, -1194, 1445), -- War on the Ramparts
(29528, 2, 0, -1412, 1745), -- War on the Ramparts
(29594, 0, 0, -1349, 1654), -- Hitting Them Where It Hurts
(29594, 1, 0, -1279, 1658), -- Hitting Them Where It Hurts
(29594, 1, 1, -1274, 1658), -- Hitting Them Where It Hurts
(29594, 1, 2, -1270, 1658), -- Hitting Them Where It Hurts
(29594, 1, 3, -1266, 1659), -- Hitting Them Where It Hurts
(29594, 1, 4, -1262, 1664), -- Hitting Them Where It Hurts
(29594, 1, 5, -1263, 1668), -- Hitting Them Where It Hurts
(29594, 1, 6, -1266, 1671), -- Hitting Them Where It Hurts
(29594, 1, 7, -1272, 1672), -- Hitting Them Where It Hurts
(29594, 1, 8, -1280, 1672), -- Hitting Them Where It Hurts
(29594, 1, 9, -1285, 1671), -- Hitting Them Where It Hurts
(29594, 1, 10, -1287, 1664), -- Hitting Them Where It Hurts
(29594, 1, 11, -1285, 1661), -- Hitting Them Where It Hurts
(29594, 2, 0, -1239, 1584), -- Hitting Them Where It Hurts
(29594, 2, 1, -1233, 1584), -- Hitting Them Where It Hurts
(29594, 2, 2, -1232, 1615), -- Hitting Them Where It Hurts
(29594, 2, 3, -1232, 1624), -- Hitting Them Where It Hurts
(29594, 2, 4, -1232, 1633), -- Hitting Them Where It Hurts
(29594, 2, 5, -1236, 1639), -- Hitting Them Where It Hurts
(29594, 2, 6, -1241, 1639), -- Hitting Them Where It Hurts
(29594, 2, 7, -1247, 1638), -- Hitting Them Where It Hurts
(29594, 2, 8, -1253, 1636), -- Hitting Them Where It Hurts
(29594, 2, 9, -1253, 1629), -- Hitting Them Where It Hurts
(29594, 2, 10, -1248, 1591), -- Hitting Them Where It Hurts
(29594, 2, 11, -1246, 1587), -- Hitting Them Where It Hurts
(29594, 3, 0, -1295, 1510), -- Hitting Them Where It Hurts
(29594, 3, 1, -1284, 1513), -- Hitting Them Where It Hurts
(29594, 3, 2, -1281, 1515), -- Hitting Them Where It Hurts
(29594, 3, 3, -1272, 1522), -- Hitting Them Where It Hurts
(29594, 3, 4, -1256, 1559), -- Hitting Them Where It Hurts
(29594, 3, 5, -1256, 1565), -- Hitting Them Where It Hurts
(29594, 3, 6, -1265, 1574), -- Hitting Them Where It Hurts
(29594, 3, 7, -1275, 1565), -- Hitting Them Where It Hurts
(29594, 3, 8, -1281, 1558), -- Hitting Them Where It Hurts
(29594, 3, 9, -1301, 1526), -- Hitting Them Where It Hurts
(29594, 3, 10, -1301, 1520), -- Hitting Them Where It Hurts
(29594, 3, 11, -1301, 1512), -- Hitting Them Where It Hurts
(29594, 4, 0, -1199, 1418), -- Hitting Them Where It Hurts
(29594, 4, 1, -1186, 1420), -- Hitting Them Where It Hurts
(29594, 4, 2, -1177, 1429), -- Hitting Them Where It Hurts
(29594, 4, 3, -1178, 1449), -- Hitting Them Where It Hurts
(29594, 4, 4, -1194, 1463), -- Hitting Them Where It Hurts
(29594, 4, 5, -1267, 1505), -- Hitting Them Where It Hurts
(29594, 4, 6, -1275, 1508), -- Hitting Them Where It Hurts
(29594, 4, 7, -1290, 1505), -- Hitting Them Where It Hurts
(29594, 4, 8, -1289, 1489), -- Hitting Them Where It Hurts
(29594, 4, 9, -1275, 1470), -- Hitting Them Where It Hurts
(29594, 4, 10, -1258, 1454), -- Hitting Them Where It Hurts
(29594, 4, 11, -1217, 1423), -- Hitting Them Where It Hurts
(29594, 5, 0, -1181, 1456), -- Hitting Them Where It Hurts
(29594, 5, 1, -1159, 1460), -- Hitting Them Where It Hurts
(29594, 5, 2, -1140, 1484), -- Hitting Them Where It Hurts
(29594, 5, 3, -1140, 1500), -- Hitting Them Where It Hurts
(29594, 5, 4, -1153, 1520), -- Hitting Them Where It Hurts
(29594, 5, 5, -1167, 1534), -- Hitting Them Where It Hurts
(29594, 5, 6, -1184, 1535), -- Hitting Them Where It Hurts
(29594, 5, 7, -1195, 1529), -- Hitting Them Where It Hurts
(29594, 5, 8, -1199, 1516), -- Hitting Them Where It Hurts
(29594, 5, 9, -1199, 1496), -- Hitting Them Where It Hurts
(29594, 5, 10, -1199, 1482), -- Hitting Them Where It Hurts
(29594, 5, 11, -1189, 1463), -- Hitting Them Where It Hurts
(29594, 6, 0, -1299, 1584), -- Hitting Them Where It Hurts
(29594, 6, 1, -1287, 1586), -- Hitting Them Where It Hurts
(29594, 6, 2, -1277, 1603), -- Hitting Them Where It Hurts
(29594, 6, 3, -1274, 1624), -- Hitting Them Where It Hurts
(29594, 6, 4, -1274, 1633), -- Hitting Them Where It Hurts
(29594, 6, 5, -1282, 1643), -- Hitting Them Where It Hurts
(29594, 6, 6, -1301, 1648), -- Hitting Them Where It Hurts
(29594, 6, 7, -1312, 1642), -- Hitting Them Where It Hurts
(29594, 6, 8, -1317, 1635), -- Hitting Them Where It Hurts
(29594, 6, 9, -1326, 1616), -- Hitting Them Where It Hurts
(29594, 6, 10, -1324, 1607), -- Hitting Them Where It Hurts
(29594, 6, 11, -1312, 1591), -- Hitting Them Where It Hurts
(29529, 0, 0, -1123, 1719), -- Demons in the Citadel
(29529, 1, 0, -1351, 1653), -- Demons in the Citadel
(29861, 1, 0, 1190, 35), -- Whatever it Takes!
(29861, 2, 0, 1132, 31), -- Whatever it Takes!
(29860, 1, 0, 1334, -91), -- Diametrically Opposed
(29860, 2, 0, 1133, 33), -- Diametrically Opposed
(28826, 0, 0, -8216, 428), -- The Eye of the Storm
(28826, 1, 0, -8216, 421), -- The Eye of the Storm
(24432, 0, 0, -4450, 3773), -- Sea Legs
(24432, 0, 1, -4511, 3883), -- Sea Legs
(24432, 0, 2, -4565, 3953), -- Sea Legs
(24432, 0, 3, -4645, 3940), -- Sea Legs
(24432, 0, 4, -4622, 3904), -- Sea Legs
(24432, 0, 5, -4534, 3786), -- Sea Legs
(24432, 1, 0, -4455, 3803), -- Sea Legs
(25281, 0, 0, -4465, 3625), -- Pay It Forward
(25281, 0, 1, -4400, 3654), -- Pay It Forward
(25281, 0, 2, -4389, 3678), -- Pay It Forward
(25281, 0, 3, -4373, 3781), -- Pay It Forward
(25281, 0, 4, -4436, 3886), -- Pay It Forward
(25281, 0, 5, -4490, 3929), -- Pay It Forward
(25281, 0, 6, -4518, 3948), -- Pay It Forward
(25281, 0, 7, -4613, 3882), -- Pay It Forward
(25281, 0, 8, -4623, 3775), -- Pay It Forward
(25281, 0, 9, -4564, 3685), -- Pay It Forward
(25281, 0, 10, -4527, 3657), -- Pay It Forward
(25281, 1, 0, -4455, 3803), -- Pay It Forward
(25405, 0, 0, -4440, 3817), -- Rest For the Weary
(25357, 0, 0, -4493, 3695), -- Buy Us Some Time
(25357, 0, 1, -4414, 3737), -- Buy Us Some Time
(25357, 0, 2, -4388, 3816), -- Buy Us Some Time
(25357, 0, 3, -4411, 3939), -- Buy Us Some Time
(25357, 0, 4, -4463, 4005), -- Buy Us Some Time
(25357, 0, 5, -4561, 4040), -- Buy Us Some Time
(25357, 0, 6, -4611, 4022), -- Buy Us Some Time
(25357, 0, 7, -4626, 3964), -- Buy Us Some Time
(25357, 0, 8, -4636, 3882), -- Buy Us Some Time
(25357, 0, 9, -4592, 3744), -- Buy Us Some Time
(25357, 0, 10, -4542, 3707), -- Buy Us Some Time
(25357, 2, 0, -4440, 3817), -- Buy Us Some Time
(25546, 0, 0, -4536, 3593), -- Traveling on Our Stomachs
(25546, 0, 1, -4441, 3728), -- Traveling on Our Stomachs
(25546, 0, 2, -4408, 3809), -- Traveling on Our Stomachs
(25546, 0, 3, -4529, 3983), -- Traveling on Our Stomachs
(25546, 0, 4, -4616, 4022), -- Traveling on Our Stomachs
(25546, 0, 5, -4662, 3913), -- Traveling on Our Stomachs
(25546, 0, 6, -4655, 3787), -- Traveling on Our Stomachs
(25546, 0, 7, -4598, 3621), -- Traveling on Our Stomachs
(25546, 0, 8, -4572, 3594), -- Traveling on Our Stomachs
(25546, 1, 0, -4440, 3817), -- Traveling on Our Stomachs
(28760, 3, 0, -624, 506), -- Vengeance for Orsis
(28760, 4, 0, -328, -11), -- Vengeance for Orsis
(28814, 0, 0, 1337, 965), -- Followers and Leaders
(28814, 3, 0, 842, 995), -- Followers and Leaders
(28814, 4, 0, 1303, 948), -- Followers and Leaders
(28814, 4, 1, 1390, 1010), -- Followers and Leaders
(28814, 4, 2, 1411, 1028), -- Followers and Leaders
(28814, 4, 3, 1420, 1070), -- Followers and Leaders
(28814, 4, 4, 1420, 1096), -- Followers and Leaders
(28814, 4, 5, 1415, 1125), -- Followers and Leaders
(28814, 4, 6, 1393, 1141), -- Followers and Leaders
(28814, 4, 7, 1283, 1115), -- Followers and Leaders
(28814, 4, 8, 1262, 1081), -- Followers and Leaders
(28814, 4, 9, 1262, 1064), -- Followers and Leaders
(28814, 4, 10, 1266, 971), -- Followers and Leaders
(28814, 4, 11, 1280, 942); -- Followers and Leaders
