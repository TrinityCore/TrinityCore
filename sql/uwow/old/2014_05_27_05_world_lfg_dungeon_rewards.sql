-- ----------------------------
-- Table structure for lfg_dungeon_rewards
-- ----------------------------
DROP TABLE IF EXISTS `lfg_dungeon_rewards`;
CREATE TABLE `lfg_dungeon_rewards` (
  `dungeonId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Dungeon entry from dbc',
  `maxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Max level at which this reward is rewarded',
  `firstQuestId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest id with rewards for first dungeon this day',
  `otherQuestId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest id with rewards for Nth dungeon this day',
  `bonusQuestId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest id with rewards for bonus objectives',
  PRIMARY KEY (`dungeonId`,`maxLevel`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `lfg_dungeon_rewards` VALUES ('258', '15', '24881', '24889', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('258', '25', '24882', '24890', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('258', '34', '24883', '24891', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('258', '45', '24884', '24892', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('258', '55', '24885', '24893', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('258', '60', '24886', '24894', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('259', '64', '24887', '24895', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('259', '70', '24888', '24896', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('260', '70', '24922', '24923', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('261', '80', '24790', '24791', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('262', '80', '24788', '24789', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('288', '85', '25485', '0', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('287', '90', '25483', '0', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('286', '85', '25484', '0', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('285', '85', '25482', '0', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('300', '85', '28907', '28908', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('301', '85', '28905', '28906', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('434', '85', '30177', '28906', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('416', '85', '30110', '30111', '0');
INSERT INTO `lfg_dungeon_rewards` VALUES ('417', '85', '30110', '30111', '0');

-- random mists normal
INSERT INTO `lfg_dungeon_rewards` VALUES ('463', '89', '31618', '31619', '0');
-- random mists heroic
INSERT INTO `lfg_dungeon_rewards` VALUES ('462', '90', '31614', '31615', '0');

-- flex raids
-- Guardians of Mogu'shan
INSERT INTO `lfg_dungeon_rewards` VALUES ('527', '90', '31274', '31275', '0');
-- The Vault of Mysteries
INSERT INTO `lfg_dungeon_rewards` VALUES ('528', '90', '31274', '31275', '0');
-- The Dread Approach
INSERT INTO `lfg_dungeon_rewards` VALUES ('529', '90', '31274', '31275', '0');
-- Nightmare of Shek'zeer
INSERT INTO `lfg_dungeon_rewards` VALUES ('530', '90', '31274', '31275', '0');
-- Terrace of Endless Spring
INSERT INTO `lfg_dungeon_rewards` VALUES ('526', '90', '31274', '31275', '0');
-- Last Stand of the Zandalari
INSERT INTO `lfg_dungeon_rewards` VALUES ('610', '90', '31274', '31275', '0');
-- Forgotten Depths
INSERT INTO `lfg_dungeon_rewards` VALUES ('611', '90', '31274', '31275', '0');
-- Halls of Flesh-Shaping
INSERT INTO `lfg_dungeon_rewards` VALUES ('612', '90', '31274', '31275', '0');
-- Pinnacle of Storms
INSERT INTO `lfg_dungeon_rewards` VALUES ('613', '90', '31274', '31275', '0');
-- Vale of Eternal Sorrows
INSERT INTO `lfg_dungeon_rewards` VALUES ('716', '90', '31274', '31275', '0');
-- Gates of Retribution
INSERT INTO `lfg_dungeon_rewards` VALUES ('717', '90', '31274', '31275', '0');
-- The Underhold
INSERT INTO `lfg_dungeon_rewards` VALUES ('724', '90', '31274', '31275', '0');
-- Downfall
INSERT INTO `lfg_dungeon_rewards` VALUES ('725', '90', '31274', '31275', '0');

-- random mists normal scenario
INSERT INTO `lfg_dungeon_rewards` VALUES ('493', '90', '31616', '31617', '0');
-- random mists heroic scenario
INSERT INTO `lfg_dungeon_rewards` VALUES ('641', '90', '32873', '31616', '32893');

UPDATE quest_template SET SpecialFlags = SpecialFlags | 8 WHERE Id IN
(SELECT firstQuestId FROM lfg_dungeon_rewards);
UPDATE quest_template SET SpecialFlags = SpecialFlags | 8 WHERE Id IN
(SELECT otherQuestId FROM lfg_dungeon_rewards);