CREATE TABLE `character_visual_enchant` (
  `guid` int(11) unsigned NOT NULL COMMENT 'guid player',
  `item_guid` int(11) unsigned NOT NULL COMMENT 'guid of item on DB',
  `enchantId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'id diplay',
  `slot` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='custom table for visual_enchant'
