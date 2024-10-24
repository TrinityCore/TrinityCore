--
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `characters_npcbot_gear_storage`;
CREATE TABLE `characters_npcbot_gear_storage` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `item_guid` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`item_guid`),
  KEY `existing_player` (`guid`),
  CONSTRAINT `characters_npcbot_gear_storage_ibfk_1` FOREIGN KEY (`item_guid`) REFERENCES `item_instance` (`guid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `existing_player` FOREIGN KEY (`guid`) REFERENCES `characters` (`guid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Bot item storage system';
