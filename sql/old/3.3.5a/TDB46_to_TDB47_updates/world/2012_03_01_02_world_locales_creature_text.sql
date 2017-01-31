DROP TABLE IF EXISTS `locales_creature_text`;
CREATE TABLE `locales_creature_text` (
  `entry` int(10) UNSIGNED NOT NULL,
  `textGroup` tinyint(3) UNSIGNED NOT NULL,
  `id` int(10) UNSIGNED NOT NULL,
  `text_loc1` text,
  `text_loc2` text,
  `text_loc3` text,
  `text_loc4` text,
  `text_loc5` text,
  `text_loc6` text,
  `text_loc7` text,
  `text_loc8` text,
  PRIMARY KEY (`entry`,`textGroup`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
