ALTER TABLE `game_corpse`
    RENAME TO `corpse`;

CREATE TABLE `corpse_grid` (
  `guid` bigint(20) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `position_x` int(11) NOT NULL default '0',
  `position_y` int(11) NOT NULL default '0',
  `cell_position_x` int(11) NOT NULL default '0',
  `cell_position_y` int(11) NOT NULL default '0',
  `grid` int(11) unsigned NOT NULL default '0' COMMENT 'Grid Identifier',
  `cell` int(11) unsigned NOT NULL default '0' COMMENT 'Cell Identifier',
  `map` int(11) unsigned NOT NULL default '0' COMMENT 'Map Identifier',
  UNIQUE KEY `idx_search` (`grid`,`cell`,`map`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Grid System';