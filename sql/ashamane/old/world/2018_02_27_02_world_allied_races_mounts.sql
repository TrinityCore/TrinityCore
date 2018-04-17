DELETE FROM `playercreateinfo_item` WHERE itemid IN (156487, 155662, 156486, 155656);
INSERT INTO `playercreateinfo_item` SELECT 27, class, 156487, 1 FROM `playercreateinfo` WHERE race = 27;
INSERT INTO `playercreateinfo_item` SELECT 28, class, 155662, 1 FROM `playercreateinfo` WHERE race = 28;
INSERT INTO `playercreateinfo_item` SELECT 29, class, 156486, 1 FROM `playercreateinfo` WHERE race = 29;
INSERT INTO `playercreateinfo_item` SELECT 30, class, 155656, 1 FROM `playercreateinfo` WHERE race = 30;
