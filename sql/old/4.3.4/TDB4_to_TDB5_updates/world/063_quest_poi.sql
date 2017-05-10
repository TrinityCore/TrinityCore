DELETE FROM `quest_poi` WHERE `questid` IN (14008, 14008, 25203, 25203, 25243, 25243, 14277, 14281, 14281, 14281, 14288);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(14008, 0, -1, 648, 605, 0, 0, 1), -- Arcane Missiles
(14008, 1, 0, 648, 605, 0, 0, 7), -- Arcane Missiles
(25203, 0, 0, 648, 544, 0, 0, 1), -- What Kind of Name is Chip, Anyway?
(25203, 1, -1, 648, 544, 0, 0, 7), -- What Kind of Name is Chip, Anyway?
(25243, 0, 4, 648, 544, 0, 0, 1), -- She Loves Me, She Loves Me NOT!
(25243, 2, -1, 648, 544, 0, 0, 1), -- She Loves Me, She Loves Me NOT!
(14277, 0, -1, 654, 545, 0, 0, 1), -- Arcane Inquiries
(14281, 1, 1, 654, 611, 0, 0, 7), -- Arcane Missiles
(14281, 2, -1, 654, 611, 0, 0, 3), -- Arcane Missiles
(14281, 3, 0, 654, 611, 0, 0, 7), -- Arcane Missiles
(14288, 0, -1, 654, 545, 0, 0, 1); -- Safety in Numbers


DELETE FROM `quest_poi_points` WHERE (`questId`=14008 AND `id`=0) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=14008 AND `id`=1) OR (`questId`=25203 AND `id`=0) OR (`questId`=25203 AND `id`=1) OR (`questId`=25243 AND `id`=0) OR (`questId`=25243 AND `id`=2) OR (`questId`=14277 AND `id`=0) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=1) OR (`questId`=14281 AND `id`=2) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14281 AND `id`=3) OR (`questId`=14288 AND `id`=0);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(14008, 0, 0, -8395, 1326), -- Arcane Missiles
(14008, 1, 0, -8427, 1299), -- Arcane Missiles
(14008, 1, 1, -8423, 1299), -- Arcane Missiles
(14008, 1, 2, -8419, 1299), -- Arcane Missiles
(14008, 1, 3, -8419, 1303), -- Arcane Missiles
(14008, 1, 4, -8419, 1306), -- Arcane Missiles
(14008, 1, 5, -8422, 1311), -- Arcane Missiles
(14008, 1, 6, -8425, 1312), -- Arcane Missiles
(14008, 1, 7, -8429, 1312), -- Arcane Missiles
(14008, 1, 8, -8433, 1312), -- Arcane Missiles
(14008, 1, 9, -8436, 1308), -- Arcane Missiles
(14008, 1, 10, -8436, 1305), -- Arcane Missiles
(14008, 1, 11, -8432, 1302), -- Arcane Missiles
(25203, 0, 0, 2463, 2133), -- What Kind of Name is Chip, Anyway?
(25203, 1, 0, 2380, 1939), -- What Kind of Name is Chip, Anyway?
(25243, 0, 0, 2064, 2592), -- She Loves Me, She Loves Me NOT!
(25243, 2, 0, 2119, 2414), -- She Loves Me, She Loves Me NOT!
(14277, 0, 0, -1690, 1328), -- Arcane Inquiries
(14281, 1, 0, -1682, 1330), -- Arcane Missiles
(14281, 1, 1, -1672, 1333), -- Arcane Missiles
(14281, 1, 2, -1664, 1341), -- Arcane Missiles
(14281, 1, 3, -1660, 1349), -- Arcane Missiles
(14281, 1, 4, -1657, 1361), -- Arcane Missiles
(14281, 1, 5, -1658, 1371), -- Arcane Missiles
(14281, 1, 6, -1665, 1383), -- Arcane Missiles
(14281, 1, 7, -1682, 1380), -- Arcane Missiles
(14281, 1, 8, -1687, 1372), -- Arcane Missiles
(14281, 1, 9, -1692, 1356), -- Arcane Missiles
(14281, 1, 10, -1694, 1346), -- Arcane Missiles
(14281, 1, 11, -1691, 1332), -- Arcane Missiles
(14281, 2, 0, -1690, 1328), -- Arcane Missiles
(14281, 3, 0, -1678, 1333), -- Arcane Missiles
(14281, 3, 1, -1669, 1340), -- Arcane Missiles
(14281, 3, 2, -1664, 1344), -- Arcane Missiles
(14281, 3, 3, -1659, 1355), -- Arcane Missiles
(14281, 3, 4, -1659, 1363), -- Arcane Missiles
(14281, 3, 5, -1662, 1373), -- Arcane Missiles
(14281, 3, 6, -1669, 1381), -- Arcane Missiles
(14281, 3, 7, -1678, 1385), -- Arcane Missiles
(14281, 3, 8, -1684, 1372), -- Arcane Missiles
(14281, 3, 9, -1693, 1351), -- Arcane Missiles
(14281, 3, 10, -1693, 1344), -- Arcane Missiles
(14281, 3, 11, -1688, 1331), -- Arcane Missiles
(14288, 0, 0, -1768, 1348); -- Safety in Numbers
