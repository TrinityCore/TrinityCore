--
DROP TABLE IF EXISTS `characters_npcbot_transmog`;
CREATE TABLE `characters_npcbot_transmog` (
  `entry` int(10) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `item_id` int(10) unsigned NOT NULL DEFAULT '0',
  `fake_id` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`,`slot`),
  CONSTRAINT `bot_id` FOREIGN KEY (`entry`) REFERENCES `characters_npcbot` (`entry`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
