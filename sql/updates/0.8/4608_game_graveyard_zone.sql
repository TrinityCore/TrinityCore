ALTER TABLE `game_graveyard_zone` 
  DROP COLUMN `ghost_map`;

UPDATE `game_graveyard_zone` as G1,`game_graveyard_zone` as G2
  SET G1.`faction` = 0
  WHERE G1.`id`=G2.`id` AND G1.`ghost_zone`=G2.`ghost_zone` AND G1.`faction`=67 AND (G2.`faction`=469 OR G2.`faction`=0);

UPDATE `game_graveyard_zone` as G1,`game_graveyard_zone` as G2
  SET G1.`faction` = 0
  WHERE G1.`id`=G2.`id` AND G1.`ghost_zone`=G2.`ghost_zone` AND G1.`faction`=469 AND (G2.`faction`=67 OR G2.`faction`=0);

DELETE FROM `game_graveyard_zone` WHERE `ghost_zone`= 0;

DROP TABLE IF EXISTS `game_graveyard_zone_new`;
CREATE TABLE `game_graveyard_zone_new` (
  `id` int(11) unsigned NOT NULL default '0',
  `ghost_zone` int(11) unsigned NOT NULL default '0',
  `faction` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`,`ghost_zone`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Trigger System';

INSERT IGNORE INTO `game_graveyard_zone_new` SELECT `id`,`ghost_zone`,`faction` FROM `game_graveyard_zone`;

DROP TABLE `game_graveyard_zone`;
RENAME TABLE `game_graveyard_zone_new` TO `game_graveyard_zone`;
