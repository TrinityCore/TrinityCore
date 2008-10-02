DROP TABLE IF EXISTS `areatrigger_graveyard_zone`;

CREATE TABLE `areatrigger_graveyard_zone` AS SELECT 
   `areatrigger_graveyard`.`id` AS `id`, 
   `areatrigger_graveyard`.`map`  AS `ghost_map`, 
   `areatrigger_graveyard`.`zone` AS `ghost_zone` 
FROM `areatrigger_graveyard` ;

ALTER TABLE `areatrigger_graveyard`
   DROP `zone`;

