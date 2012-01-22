DROP TABLE IF EXISTS `locales_creature_text`;
CREATE TABLE `locales_creature_text` (
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `groupid` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `id` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `text_loc1` longtext,
  `text_loc2` longtext,
  `text_loc3` longtext,
  `text_loc4` longtext,
  `text_loc5` longtext,
  `text_loc6` longtext,
  `text_loc7` longtext,
  `text_loc8` longtext,
  PRIMARY KEY (`entry`,`groupid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;