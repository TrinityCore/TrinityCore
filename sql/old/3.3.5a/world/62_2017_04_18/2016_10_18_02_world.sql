--
DELETE FROM `quest_template_addon` WHERE `ID`=8312;
DELETE FROM `conditions` WHERE `SourceGroup`=15354 AND `SourceEntry`=20557;
INSERT INTO `conditions` VALUES
(23, 15354, 20557, 0, 0, 8, 0, 8312, 0, 0, 0, 0, 0, "", "Item Hallow's End Pumpkin Treat sold by Rachelle Gothena requires quest Hallow's End Treats for Spoops! rewarded");
