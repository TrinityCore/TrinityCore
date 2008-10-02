ALTER TABLE `game_graveyard_zone`
  ADD COLUMN `faction` int(11) unsigned NOT NULL default '0' AFTER `ghost_zone`;

UPDATE `game_graveyard_zone`,`game_graveyard`
  SET `game_graveyard_zone`.`faction`     = `game_graveyard`.`faction`
  WHERE `game_graveyard_zone`.`id` = `game_graveyard`.`id`;


DROP TABLE IF EXISTS `game_graveyard`;
