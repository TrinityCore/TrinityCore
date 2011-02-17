DROP TABLE IF EXISTS `player_factionchange_items`;
CREATE TABLE `player_factionchange_items` (
 `race_A` int(8) NOT NULL,
 `alliance_id` int(8) NOT NULL,
 `commentA` text,
 `race_H` int(8) NOT NULL,
 `horde_id` int(8) NOT NULL,
 `commentH` text,
PRIMARY KEY (`alliance_id`,`horde_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
