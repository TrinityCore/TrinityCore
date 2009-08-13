ALTER TABLE characters DROP COLUMN bgid;
ALTER TABLE characters DROP COLUMN bgteam;
ALTER TABLE characters DROP COLUMN bgmap;
ALTER TABLE characters DROP COLUMN bgx;
ALTER TABLE characters DROP COLUMN bgy;
ALTER TABLE characters DROP COLUMN bgz;
ALTER TABLE characters DROP COLUMN bgo;

DROP TABLE IF EXISTS `character_battleground_data`;
CREATE TABLE `character_battleground_data` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `instance_id` int(11) unsigned NOT NULL default '0',
  `team` int(11) unsigned NOT NULL default '0',
  `join_x` float NOT NULL default '0',
  `join_y` float NOT NULL default '0',
  `join_z` float NOT NULL default '0',
  `join_o` float NOT NULL default '0',
  `join_map` int(11) NOT NULL default '0',
  `taxi_start` int(11) NOT NULL default '0',
  `taxi_end` int(11) NOT NULL default '0',
  `mount_spell` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';
