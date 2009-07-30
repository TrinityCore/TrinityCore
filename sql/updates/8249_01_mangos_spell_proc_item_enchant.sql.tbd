ALTER TABLE db_version CHANGE COLUMN required_8247_01_mangos_spell_bonus_data required_8249_01_mangos_spell_proc_item_enchant bit;

DROP TABLE IF EXISTS `spell_proc_item_enchant`;
CREATE TABLE `spell_proc_item_enchant` (
  `entry` mediumint unsigned NOT NULL,
  `ppmRate` float NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_proc_item_enchant` (`entry`, `ppmRate`) VALUES
(8034, 9),        -- Frostbrand Weapon
(8680, 8.5714),   -- Instant Poison
(13218, 21.4286); -- Wound Poison
