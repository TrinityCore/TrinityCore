CREATE TABLE `pet_stats` (
  `entry` int(10) NOT NULL,
  `hp` float NOT NULL DEFAULT '0.5',
  `ap` float NOT NULL DEFAULT '1',
  `ap_type` int(10) NOT NULL DEFAULT '0',
  `spd` float NOT NULL DEFAULT '1',
  `school_mask` int(10) NOT NULL DEFAULT '127',
  `state` int(10) NOT NULL DEFAULT '0',
  `energy` int(10) NOT NULL DEFAULT '0',
  `energy_type` int(10) NOT NULL DEFAULT '0',
  `armor` float NOT NULL DEFAULT '1',
  `type` int(10) NOT NULL DEFAULT '0',
  `comment` text NOT NULL,
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `spell_trigger`
ADD `spell_cooldown` int(8) DEFAULT '0' NOT NULL AFTER spell_trigger;
