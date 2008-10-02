
DROP TABLE IF EXISTS `spell_teleport`;
CREATE TABLE `spell_teleport` (
  `id` int(11) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `target_map` int(11) unsigned NOT NULL default '0',
  `target_position_x` float NOT NULL default '0',
  `target_position_y` float NOT NULL default '0',
  `target_position_z` float NOT NULL default '0',
  `target_orientation` float NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Spell System';

INSERT INTO `spell_teleport` 
SELECT `id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation` 
FROM `areatrigger_teleport`;

DELETE FROM `spell_teleport` WHERE `target_position_x` = 0 AND `target_position_y` = 0 AND `target_position_z` = 0;
