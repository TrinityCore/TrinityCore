--
DROP TABLE IF EXISTS `characters_npcbot_group_member`;
CREATE TABLE `characters_npcbot_group_member` (
  `guid` int(10) unsigned NOT NULL,
  `entry` int(10) unsigned NOT NULL,
  `memberFlags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `subgroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `roles` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
